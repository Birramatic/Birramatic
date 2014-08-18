/***************************************************************
 * Name:      BirraMaticMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Iván del Castillo ()
 * Created:   2014-08-02
 * Copyright: Iván del Castillo ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include <wx/timer.h>
#include <wx/msgdlg.h>
#include <wx/textfile.h>
#include <wx/filedlg.h>
#include "BirraMaticMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}



BirraMaticDialog::BirraMaticDialog(wxDialog *dlg)
    : GUIDialog(dlg)
{
    extern bool m_HeaterStatus, m_PumpStatus, m_IsAuto;
    extern int m_UpdTemp;
    extern double m_TargetTemp;

    m_TimerUpdate = new wxTimer(this, wxID_ANY);
    this->Connect(m_TimerUpdate->GetId(), wxEVT_TIMER, wxTimerEventHandler(BirraMaticDialog::OnUpdate), NULL, this);
    m_TimerUpdate->Start(1000);

    m_UpdTemp=11; m_TargetTemp=0; m_CountDown=0;
    m_HeaterStatus = m_PumpStatus = m_IsAuto = false;
    m_WaitForTemperature = true;
    OnSwitchOffHeater();
}

BirraMaticDialog::~BirraMaticDialog()
{
}

void BirraMaticDialog::OnClose(wxCommandEvent &event)
{
    int i = wxMessageBox(wxString::FromUTF8("YES = Apagar el equipo\nNO=Salir del programa sin apagar\nCANCEL = Anular"),
            wxString::FromUTF8("Atención"), wxYES | wxNO | wxCANCEL);

    if(i == wxCANCEL) return;
    if(i == wxYES) system("sudo poweroff");
    Destroy();

}

void BirraMaticDialog::OnCalibrateTouchScreen(wxCommandEvent &event)
{
    wxExecute("sudo /home/Birramatic/scripts/./Calibrate_TS.sh");
}

void BirraMaticDialog::OnManualPump(wxCommandEvent &event)
{
    extern bool m_PumpStatus;
    extern int m_UpdTemp;
    wxString st;

    if(m_PumpStatus) st = wxString::FromUTF8("La bomba se apagará\nConfirme la operación");
    else st = wxString::FromUTF8("La bomba se conectará\nConfirme la operación");

    if( wxMessageBox(st, wxString::FromUTF8("Atención"), wxOK | wxCANCEL) == wxOK)
    {
        m_PumpStatus = !m_PumpStatus;
        m_UpdTemp = 11;
    }
}

void BirraMaticDialog::OnManualTemperature(wxCommandEvent &event)
{
    SelTempDialog *m_TDlg = new SelTempDialog(this);

    m_TDlg->Show();
}

void BirraMaticDialog::OnMute(wxCommandEvent &event)
{
    system("echo 0 | sudo tee /sys/class/gpio/gpio7/value");
}

void BirraMaticDialog::OnOpen(wxCommandEvent &event)
{
    extern bool m_MashPause[], m_IsAuto, m_PumpStatus;
    extern int m_MashSteps, m_UpdTemp, m_ActStep, m_MashTime[];
    extern double m_MashTemperature[], m_TargetTemp;
    extern wxArrayString m_MashSchedule;
    long l;
    double d;
    wxString st;
    wxTextFile m_TxtFile;

    wxSetWorkingDirectory("/home/ftp");
    wxFileDialog* OpenDialog = new wxFileDialog(
		this, wxString::FromUTF8("Programa de maceración"), wxEmptyString, wxEmptyString,
		"Birramatic (*.brm)|*.brm", wxFD_OPEN, wxDefaultPosition);

	if (OpenDialog->ShowModal() == wxID_OK)
	{
		if(m_TxtFile.Open(OpenDialog->GetPath()))
        {
            m_TxtFile.GetFirstLine();
            m_MashSteps=0;
            do
            {
                st = m_TxtFile.GetNextLine();
                if(st.Len() > 5)
                {
                    st.BeforeFirst('-').ToDouble(&d); m_MashTemperature[m_MashSteps]=d;
                    st = st.AfterFirst('-');
                    st.BeforeFirst('-').ToLong(&l); m_MashTime[m_MashSteps]=(int)l;
                    st = st.AfterFirst('-');
                    st.BeforeFirst('-').ToCLong(&l);
                    if(l) m_MashPause[m_MashSteps]=true; else m_MashPause[m_MashSteps]=false;
                    st = st.AfterFirst('-');

                    m_MashSchedule.Insert(st, m_MashSteps, 1);
                    m_MashSteps++;
                }

            }while(!m_TxtFile.Eof());
            m_TxtFile.Close();
            m_IsAuto = true; m_ActStep=0;
            m_WaitForTemperature=true; m_PumpStatus = true;
            m_TargetTemp = m_MashTemperature[0];
            m_CountDown = m_MashTime[0]*60;

            wxButton *m_Button = (wxButton*)FindWindow(wxID_BUTTON_PAUSE); m_Button->Enable(true);
            m_Button = (wxButton*)FindWindow(wxID_BUTTON_SKIP); m_Button->Enable(true);
            m_Button = (wxButton*)FindWindow(wxID_BUTTON_OPEN); m_Button->Enable(false);
            m_Button = (wxButton*)FindWindow(wxID_BUTTON_TEMPERATURE); m_Button->Enable(false);
            m_Button = (wxButton*)FindWindow(wxID_BUTTON_TOUCH); m_Button->Enable(false);

        }

	}

	OpenDialog->Destroy();
	m_UpdTemp=11;
}

void BirraMaticDialog::OnUpdate(wxTimerEvent &event)
{
    extern bool m_IsAuto, m_MashPause[];
    extern double m_Offset, m_Coef_ax, m_Coef_b, m_TargetTemp, m_Hysteresis_On, m_Hysteresis_Off, m_MashTemperature[];
    extern int m_UpdTemp, m_ActStep, m_MashSteps, m_MashTime[];
    extern wxArrayString m_MashSchedule;
    double m_Temperature;
    int h, m, s;
    wxString st;
    wxTextFile m_TxtFile;
    wxTextCtrl *m_TxtCtrl;

    wxStaticText *m_Text = (wxStaticText*)FindWindow(wxID_TXT_Clock);

    wxDateTime now = wxDateTime::Now();
    m_Text->SetLabel(now.FormatISOTime());

    m_Text = (wxStaticText*)FindWindow(wxID_TXT_Timer);
    if(!m_WaitForTemperature && m_CountDown)
    {
        m_CountDown--;
        h = m_CountDown/3600;
        m = (m_CountDown - h*3600)/60;
        s = m_CountDown - h*3600 - m*60;
        m_Text->SetLabel(wxString::Format("%02d:%02d:%02d", h, m, s));
    }
    else if(m_IsAuto)
    {
        m_Text->SetLabel(wxString::FromUTF8("Espere"));
    }

    if( ++m_UpdTemp > 3)
    {
        m_UpdTemp=0;

        if(m_TxtFile.Open("/mnt/RAMDisk/Temperature"))
        {
            m_TxtFile.GetFirstLine().ToDouble(&m_Temperature);
            m_TxtFile.Close();
            m_Temperature = (m_Temperature - m_Coef_b)/m_Coef_ax + m_Offset;
        }
        else Destroy();

        m_Text = (wxStaticText*)FindWindow(wxID_TXT_Temperature);
        m_Text->SetLabel(wxString::Format(wxString::FromUTF8("%.1f ºC"), m_Temperature));

        if( (m_Temperature-m_Hysteresis_On) < m_TargetTemp) OnSwitchOnHeater();
        if( (m_Temperature + m_Hysteresis_Off) > m_TargetTemp) OnSwitchOffHeater();

        if(m_IsAuto)
        {
            if(m_WaitForTemperature)
            {
                if( (m_Temperature >= (m_TargetTemp-m_Hysteresis_Off))) m_WaitForTemperature = false;
            }
            else
            {
                if(!m_CountDown)
                {
                    system("echo 1 | sudo tee /sys/class/gpio/gpio7/value");
                    if(m_MashPause[m_ActStep])
                    {
                        wxMessageBox("Pulse OK para agagar la alarma", wxString::FromUTF8("Atención"), wxOK);
                        system("echo 0 | sudo tee /sys/class/gpio/gpio7/value");
                        st = m_MashSchedule[m_ActStep] + "\nPulse OK para continuar";
                        wxMessageBox(st, wxString::FromUTF8("Atención"), wxOK);
                    }
                    m_ActStep++;
                    if(m_ActStep == m_MashSteps)
                    {
                        m_IsAuto=false;
                        m_TargetTemp=0;

                        wxButton *m_Button = (wxButton*)FindWindow(wxID_BUTTON_OPEN); m_Button->Enable(true);
                        m_Button = (wxButton*)FindWindow(wxID_BUTTON_TEMPERATURE); m_Button->Enable(true);
                        m_Button = (wxButton*)FindWindow(wxID_BUTTON_PAUSE); m_Button->Enable(false);
                        m_Button = (wxButton*)FindWindow(wxID_BUTTON_SKIP); m_Button->Enable(false);
                        m_Button = (wxButton*)FindWindow(wxID_BUTTON_TOUCH); m_Button->Enable(true);
                        return;
                    }
                    else
                    {
                        m_CountDown = m_MashTime[m_ActStep]*60;
                        m_TargetTemp = m_MashTemperature[m_ActStep];
                        m_UpdTemp = 11;
                        m_WaitForTemperature = true;
                    }
                }
            }
            m_TxtCtrl = (wxTextCtrl*)FindWindow(wxID_TEXTCTRL_1);
            m_TxtCtrl->SetValue("Actual: " + m_MashSchedule.Item(m_ActStep));
            m_TxtCtrl = (wxTextCtrl*)FindWindow(wxID_TEXTCTRL_2);
            if( m_ActStep < m_MashSteps)
            {
                m_TargetTemp = m_MashTemperature[m_ActStep];
                if( (m_ActStep+1) != m_MashSteps) m_TxtCtrl->SetValue(wxString::FromUTF8("Próximo: ") + m_MashSchedule.Item(m_ActStep+1));
                else m_TxtCtrl->SetValue(wxString::FromUTF8("Próximo: Fin"));
            }
        }
        else
        {
            m_TxtCtrl = (wxTextCtrl*)FindWindow(wxID_TEXTCTRL_1);
            m_TxtCtrl->SetValue("Modo manual");
            m_TxtCtrl = (wxTextCtrl*)FindWindow(wxID_TEXTCTRL_2);
            m_TxtCtrl->SetValue("");
        }
    }
    ManageGPIOs();
}

void BirraMaticDialog::OnSwitchOnHeater(void)
{
    extern bool m_HeaterStatus, m_PumpStatus;

    m_HeaterStatus = true; m_PumpStatus = true;
    OnUpdateStatus();
}

void BirraMaticDialog::OnSwitchOffHeater(void)
{
    extern bool m_HeaterStatus;

    m_HeaterStatus = false;
    OnUpdateStatus();
}

void BirraMaticDialog::OnUpdateStatus(void)
{
    extern bool m_HeaterStatus, m_PumpStatus;
    extern double m_TargetTemp;
    wxString st;

    wxStaticText *m_Text = (wxStaticText*)FindWindow(wxID_TXT_STATUS);

    if(m_HeaterStatus) st = wxString::Format(wxString::FromUTF8("Calentando a: %.1f ºC"), m_TargetTemp);
    else st = "Calentador apagado";
    if(m_PumpStatus) st = st + "\nBomba encedida";
    else st = st + "\nBomba apagada";

    m_Text->SetLabel(st);
}

void BirraMaticDialog::OnStart(wxCommandEvent &event)
{
    extern bool m_IsAuto;
    extern int m_UpdTemp;

    m_IsAuto=true; m_CountDown = m_BackupCD;

    wxButton *m_Button = (wxButton*)FindWindow(wxID_BUTTON_START); m_Button->Enable(false);
    m_Button = (wxButton*)FindWindow(wxID_BUTTON_PAUSE); m_Button->Enable(true);
    m_Button = (wxButton*)FindWindow(wxID_BUTTON_SKIP); m_Button->Enable(true);
    m_Button = (wxButton*)FindWindow(wxID_BUTTON_TEMPERATURE); m_Button->Enable(false);

    m_UpdTemp = 11;
}

void BirraMaticDialog::OnPause(wxCommandEvent &event)
{
    extern bool m_IsAuto;
    extern int m_UpdTemp;

    m_IsAuto = false; m_BackupCD=m_CountDown; m_CountDown = 0;
    wxMessageBox(wxString::FromUTF8("Operación pausada\nPulsar continuar para reanudarla"), wxString::FromUTF8("Atención"), wxOK);

    wxButton *m_Button = (wxButton*)FindWindow(wxID_BUTTON_START); m_Button->Enable(true);
    m_Button = (wxButton*)FindWindow(wxID_BUTTON_PAUSE); m_Button->Enable(false);
    m_Button = (wxButton*)FindWindow(wxID_BUTTON_SKIP); m_Button->Enable(false);
    m_Button = (wxButton*)FindWindow(wxID_BUTTON_TEMPERATURE); m_Button->Enable(true);

    m_UpdTemp = 11;
}

void BirraMaticDialog::OnSkip(wxCommandEvent & event)
{
    extern int m_UpdTemp;
    extern double m_TargetTemp;

    if(wxMessageBox(wxString::FromUTF8("Confirme que desea saltar\nel paso actual"), wxString::FromUTF8("Atención"), wxOK | wxCANCEL) == wxOK)
    {
       m_CountDown = 0;
       m_TargetTemp = 0;
    }

    m_UpdTemp = 11;
}

void BirraMaticDialog::ManageGPIOs(void)
{
    extern bool m_PumpStatus, m_HeaterStatus;

    if(m_HeaterStatus) system("echo 1 | sudo tee /sys/class/gpio/gpio117/value");
    else system("echo 0 | sudo tee /sys/class/gpio/gpio117/value");

    if(m_PumpStatus) system("echo 1 | sudo tee /sys/class/gpio/gpio26/value");
    else system("echo 0 | sudo tee /sys/class/gpio/gpio26/value");
}



SelTempDialog::SelTempDialog( wxWindow* parent)
:
SelTempDialogFunc( parent )
{
    m_TgT = 60.0;
}

void SelTempDialog::OnTargetClose(wxCommandEvent &event)
{
    extern int m_UpdTemp;
    extern double m_TargetTemp;

    m_TargetTemp = m_TgT;
    m_UpdTemp = 11;
    Close(true);
}

void SelTempDialog::OnChangeTemp(wxCommandEvent &event)
{
    if(event.GetId()==wxID_BUTTON_MINUS1) m_TgT -= 1.0;
    if(event.GetId()==wxID_BUTTON_MINUS)  m_TgT -= 0.1;
    if(event.GetId()==wxID_BUTTON_PLUS)   m_TgT += 0.1;
    if(event.GetId()==wxID_BUTTON_PLUS1)  m_TgT += 1.0;

    wxStaticText *m_Text = (wxStaticText*)FindWindow(wxID_TXT_TARGET_TEMP);
    m_Text->SetLabel(wxString::Format(wxString::FromUTF8("%.1f ºC"), m_TgT));
}




