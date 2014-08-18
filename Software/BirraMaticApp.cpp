/***************************************************************
 * Name:      BirraMaticApp.cpp
 * Purpose:   Code for Application Class
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

#include <wx/config.h>
#include "BirraMaticApp.h"
#include "BirraMaticMain.h"

bool m_HeaterStatus;
bool m_PumpStatus;
bool m_IsAuto;
int m_UpdTemp;
int m_MashSteps;
int m_ActStep;
double m_TargetTemp;
double m_Hysteresis_On;
double m_Hysteresis_Off;
double m_Offset;
double m_Coef_ax;
double m_Coef_b;

wxArrayString m_MashSchedule;
bool m_MashPause[20];
double m_MashTemperature[20];
int m_MashTime[20];

IMPLEMENT_APP(BirraMaticApp);

bool BirraMaticApp::OnInit()
{
    m_TargetTemp = 0;

    wxConfigBase *pConfig = wxConfigBase::Get();
    m_Hysteresis_On = pConfig->Read("Config/HysteresisOn_x10", (long)5)/10.0;
    m_Hysteresis_Off= pConfig->Read("Config/HysteresisOff_x10", (long)3)/10.0;
    m_Offset  = pConfig->Read("Config/TOffset_x10", (long)0)/10.0;
    m_Coef_ax = pConfig->Read("Config/Coef_ax_x1000", (long)1000)/1000.0;
    m_Coef_b  = pConfig->Read("Config/Coef_b_x1000", (long)0)/1000.0;

    pConfig->SetRecordDefaults();

    BirraMaticDialog* dlg = new BirraMaticDialog(0L);

    dlg->Show();
    return true;
}

int BirraMaticApp::OnExit()
{
    wxConfigBase *pConfig = wxConfigBase::Get();
    if( pConfig == NULL ) return 1;

    pConfig->Write("Config/HysteresisOn_x10", (long)(m_Hysteresis_On*10.0));
    pConfig->Write("Config/HysteresisOff_x10", (long)(m_Hysteresis_Off*10.0));
    pConfig->Write("Config/TOffset_x10", (long)(m_Offset*10.0));
    pConfig->Write("Config/Coef_ax_x1000", (long)(m_Coef_ax*1000.0));
    pConfig->Write("Config/Coef_b_x1000", (long)(m_Coef_b*1000.0));


    delete wxConfigBase::Set((wxConfigBase *) NULL);

    return 1;
}
