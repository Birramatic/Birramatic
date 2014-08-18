///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 27 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIDIALOG_H__
#define __GUIDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class GUIDialog
///////////////////////////////////////////////////////////////////////////////
class GUIDialog : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			wxID_BUTTON_OPEN = 1000,
			wxID_BUTTON_TEMPERATURE,
			wxID_BUTTON_PUMP,
			wxID_BUTTON_START,
			wxID_BUTTON_PAUSE,
			wxID_BUTTON_SKIP,
			wxID_BUTTON_TOUCH,
			wxID_TXT_Clock,
			wxID_TXT_Temperature,
			wxID_TXT_Timer,
			wxID_TEXTCTRL_1,
			wxID_TEXTCTRL_2,
			wxID_TXT_STATUS
		};
		
		wxBitmapButton* m_bpButton1;
		wxBitmapButton* m_bpButton2;
		wxBitmapButton* m_bpButton3;
		wxBitmapButton* m_bpButton4;
		wxBitmapButton* m_bpButton5;
		wxBitmapButton* m_bpButton6;
		wxBitmapButton* m_bpButton7;
		wxBitmapButton* m_bpButton8;
		wxBitmapButton* m_bpButton9;
		wxStaticText* m_staticText4;
		wxStaticText* m_staticText2;
		wxStaticLine* m_staticline2;
		wxStaticText* m_staticText3;
		wxStaticLine* m_staticline3;
		wxTextCtrl* m_textCtrl2;
		wxTextCtrl* m_textCtrl3;
		wxStaticText* m_staticText41;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnManualTemperature( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnManualPump( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStart( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPause( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSkip( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClose( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCalibrateTouchScreen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMute( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Birra-Matic"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = 0 ); 
		~GUIDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SelTempDialogFunc
///////////////////////////////////////////////////////////////////////////////
class SelTempDialogFunc : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			wxID_TXT_TARGET_TEMP = 1000,
			wxID_BUTTON_MINUS1,
			wxID_BUTTON_MINUS,
			wxID_BUTTON_PLUS,
			wxID_BUTTON_PLUS1
		};
		
		wxStaticText* m_staticText5;
		wxStaticText* m_staticText6;
		wxBitmapButton* m_bpButton10;
		wxButton* m_button1;
		wxButton* m_button2;
		wxButton* m_button3;
		wxButton* m_button4;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTargetClose( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChangeTemp( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SelTempDialogFunc( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0 ); 
		~SelTempDialogFunc();
	
};

#endif //__GUIDIALOG_H__
