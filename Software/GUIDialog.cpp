///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 27 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIDialog.h"

#include "bitmaps/Thermometer.xpm"
#include "bitmaps/Touch_Screen_48x48.xpm"
#include "bitmaps/Valve.xpm"
#include "bitmaps/audio_volume_muted.xpm"
#include "bitmaps/document_open.xpm"
#include "bitmaps/exit_48x48.xpm"
#include "bitmaps/pause_48x48.xpm"
#include "bitmaps/skip_forward.xpm"
#include "bitmaps/start_48x48.xpm"

///////////////////////////////////////////////////////////////////////////

GUIDialog::GUIDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 480,272 ), wxSize( 480,272 ) );
	this->SetBackgroundColour( wxColour( 233, 236, 142 ) );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 3, 3, 0, 0 );
	
	m_bpButton1 = new wxBitmapButton( this, wxID_BUTTON_OPEN, wxBitmap( document_open_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer1->Add( m_bpButton1, 0, wxALL, 5 );
	
	m_bpButton2 = new wxBitmapButton( this, wxID_BUTTON_TEMPERATURE, wxBitmap( Thermometer_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer1->Add( m_bpButton2, 0, wxALL, 5 );
	
	m_bpButton3 = new wxBitmapButton( this, wxID_BUTTON_PUMP, wxBitmap( Valve_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer1->Add( m_bpButton3, 0, wxALL, 5 );
	
	m_bpButton4 = new wxBitmapButton( this, wxID_BUTTON_START, wxBitmap( start_48x48_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton4->Enable( false );
	
	gSizer1->Add( m_bpButton4, 0, wxALL, 5 );
	
	m_bpButton5 = new wxBitmapButton( this, wxID_BUTTON_PAUSE, wxBitmap( pause_48x48_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton5->Enable( false );
	
	gSizer1->Add( m_bpButton5, 0, wxALL, 5 );
	
	m_bpButton6 = new wxBitmapButton( this, wxID_BUTTON_SKIP, wxBitmap( skip_forward_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton6->Enable( false );
	
	gSizer1->Add( m_bpButton6, 0, wxALL, 5 );
	
	m_bpButton7 = new wxBitmapButton( this, wxID_ANY, wxBitmap( exit_48x48_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer1->Add( m_bpButton7, 0, wxALL, 5 );
	
	m_bpButton8 = new wxBitmapButton( this, wxID_BUTTON_TOUCH, wxBitmap( Touch_Screen_48x48_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer1->Add( m_bpButton8, 0, wxALL, 5 );
	
	m_bpButton9 = new wxBitmapButton( this, wxID_ANY, wxBitmap( audio_volume_muted_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer1->Add( m_bpButton9, 0, wxALL, 5 );
	
	
	fgSizer2->Add( gSizer1, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_TXT_Clock, wxT("00:00:00"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText4->Wrap( -1 );
	m_staticText4->SetFont( wxFont( 14, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer3->Add( m_staticText4, 0, wxALL, 15 );
	
	
	fgSizer2->Add( bSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP, 5 );
	
	
	fgSizer1->Add( fgSizer2, 1, wxEXPAND|wxTOP, 10 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 7, 1, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText2 = new wxStaticText( this, wxID_TXT_Temperature, wxT("20.0 ºC"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( 35, 70, 90, 92, false, wxEmptyString ) );
	m_staticText2->SetForegroundColour( wxColour( 7, 138, 8 ) );
	m_staticText2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	fgSizer3->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer3->Add( m_staticline2, 0, wxEXPAND|wxBOTTOM, 10 );
	
	m_staticText3 = new wxStaticText( this, wxID_TXT_Timer, wxT("00:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetFont( wxFont( 22, 70, 90, 92, false, wxEmptyString ) );
	m_staticText3->SetForegroundColour( wxColour( 5, 7, 251 ) );
	
	fgSizer3->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticline3 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer3->Add( m_staticline3, 0, wxEXPAND|wxTOP|wxBOTTOM, 10 );
	
	m_textCtrl2 = new wxTextCtrl( this, wxID_TEXTCTRL_1, wxT("Status Text 1"), wxDefaultPosition, wxSize( 255,30 ), 0 );
	m_textCtrl2->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer3->Add( m_textCtrl2, 0, wxALL, 5 );
	
	m_textCtrl3 = new wxTextCtrl( this, wxID_TEXTCTRL_2, wxT("Status Text 2"), wxDefaultPosition, wxSize( 255,30 ), 0 );
	m_textCtrl3->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer3->Add( m_textCtrl3, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_staticText41 = new wxStaticText( this, wxID_TXT_STATUS, wxT("Heater: On   Pump: On"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	m_staticText41->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer3->Add( m_staticText41, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	fgSizer1->Add( fgSizer3, 1, wxEXPAND|wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( fgSizer1 );
	this->Layout();
	fgSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIDialog::OnClose ) );
	m_bpButton1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnOpen ), NULL, this );
	m_bpButton2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnManualTemperature ), NULL, this );
	m_bpButton3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnManualPump ), NULL, this );
	m_bpButton4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnStart ), NULL, this );
	m_bpButton5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnPause ), NULL, this );
	m_bpButton6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnSkip ), NULL, this );
	m_bpButton7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnClose ), NULL, this );
	m_bpButton8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnCalibrateTouchScreen ), NULL, this );
	m_bpButton9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnMute ), NULL, this );
}

GUIDialog::~GUIDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIDialog::OnClose ) );
	m_bpButton1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnOpen ), NULL, this );
	m_bpButton2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnManualTemperature ), NULL, this );
	m_bpButton3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnManualPump ), NULL, this );
	m_bpButton4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnStart ), NULL, this );
	m_bpButton5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnPause ), NULL, this );
	m_bpButton6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnSkip ), NULL, this );
	m_bpButton7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnClose ), NULL, this );
	m_bpButton8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnCalibrateTouchScreen ), NULL, this );
	m_bpButton9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnMute ), NULL, this );
	
}

SelTempDialogFunc::SelTempDialogFunc( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 480,272 ), wxSize( 480,272 ) );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("TEMPERATURA OBJETIVO"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer5->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer4->Add( fgSizer5, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText6 = new wxStaticText( this, wxID_TXT_TARGET_TEMP, wxT("60.0 ºC"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	m_staticText6->SetFont( wxFont( 60, 70, 90, 92, false, wxEmptyString ) );
	m_staticText6->SetForegroundColour( wxColour( 251, 0, 0 ) );
	
	fgSizer6->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 6, 0, 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_bpButton10 = new wxBitmapButton( this, wxID_ANY, wxBitmap( exit_48x48_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer7->Add( m_bpButton10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 10 );
	
	m_button1 = new wxButton( this, wxID_BUTTON_MINUS1, wxT("-1 ºC"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button1->SetFont( wxFont( 12, 70, 90, 92, false, wxEmptyString ) );
	m_button1->SetMinSize( wxSize( 70,70 ) );
	
	fgSizer7->Add( m_button1, 0, wxALL, 15 );
	
	m_button2 = new wxButton( this, wxID_BUTTON_MINUS, wxT("-0.1 ºC"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button2->SetFont( wxFont( 9, 70, 90, 92, false, wxEmptyString ) );
	m_button2->SetMinSize( wxSize( 70,70 ) );
	
	fgSizer7->Add( m_button2, 0, wxALL, 15 );
	
	m_button3 = new wxButton( this, wxID_BUTTON_PLUS, wxT("+0.1 ºC"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button3->SetFont( wxFont( 9, 70, 90, 92, false, wxEmptyString ) );
	m_button3->SetMinSize( wxSize( 70,70 ) );
	
	fgSizer7->Add( m_button3, 0, wxALL, 15 );
	
	m_button4 = new wxButton( this, wxID_BUTTON_PLUS1, wxT("+1 ºC"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button4->SetFont( wxFont( 12, 70, 90, 92, false, wxEmptyString ) );
	m_button4->SetMinSize( wxSize( 70,70 ) );
	
	fgSizer7->Add( m_button4, 0, wxALL, 15 );
	
	
	fgSizer6->Add( fgSizer7, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	fgSizer4->Add( fgSizer6, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( fgSizer4 );
	this->Layout();
	fgSizer4->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpButton10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelTempDialogFunc::OnTargetClose ), NULL, this );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelTempDialogFunc::OnChangeTemp ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelTempDialogFunc::OnChangeTemp ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelTempDialogFunc::OnChangeTemp ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelTempDialogFunc::OnChangeTemp ), NULL, this );
}

SelTempDialogFunc::~SelTempDialogFunc()
{
	// Disconnect Events
	m_bpButton10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelTempDialogFunc::OnTargetClose ), NULL, this );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelTempDialogFunc::OnChangeTemp ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelTempDialogFunc::OnChangeTemp ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelTempDialogFunc::OnChangeTemp ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelTempDialogFunc::OnChangeTemp ), NULL, this );
	
}
