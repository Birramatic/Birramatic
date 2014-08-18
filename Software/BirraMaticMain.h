/***************************************************************
 * Name:      BirraMaticMain.h
 * Purpose:   Defines Application Frame
 * Author:    Iván del Castillo ()
 * Created:   2014-08-02
 * Copyright: Iván del Castillo ()
 * License:
 **************************************************************/

#ifndef BIRRAMATICMAIN_H
#define BIRRAMATICMAIN_H


#include <wx/timer.h>
#include "BirraMaticApp.h"



#include "GUIDialog.h"

class BirraMaticDialog: public GUIDialog
{
    public:
        BirraMaticDialog(wxDialog *dlg);
        ~BirraMaticDialog();

        void OnUpdate(wxTimerEvent &event);
        void OnCalibrateTouchScreen(wxCommandEvent &event);
        void OnManualPump(wxCommandEvent &event);
        void OnManualTemperature(wxCommandEvent &event);
        void OnOpen(wxCommandEvent &event);
        void OnStart(wxCommandEvent &event);
        void OnPause(wxCommandEvent &event);
        void OnSkip(wxCommandEvent & event);
        void OnMute(wxCommandEvent& event);

    private:
        virtual void OnClose(wxCommandEvent& event);
        void OnSwitchOnHeater(void);
        void OnSwitchOffHeater(void);
        void OnUpdateStatus(void);
        void ManageGPIOs(void);

        bool m_WaitForTemperature;
        int m_CountDown, m_BackupCD;
        wxTimer *m_TimerUpdate;

};
#endif // BIRRAMATICMAIN_H


#ifndef DIALOGS_H_INCLUDED
#define DIALOGS_H_INCLUDED

#include "BirraMaticMain.h"


class SelTempDialog : public SelTempDialogFunc
{
public:
    SelTempDialog(wxWindow *parent);

private:
    double m_TgT;
    void OnTargetClose(wxCommandEvent &event);
    void OnChangeTemp(wxCommandEvent &event);

};


#endif // DIALOGS_H_INCLUDED





