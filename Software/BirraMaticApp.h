/***************************************************************
 * Name:      BirraMaticApp.h
 * Purpose:   Defines Application Class
 * Author:    Iván del Castillo ()
 * Created:   2014-08-02
 * Copyright: Iván del Castillo ()
 * License:
 **************************************************************/

#ifndef BIRRAMATICAPP_H
#define BIRRAMATICAPP_H

#include <wx/app.h>

class BirraMaticApp : public wxApp
{
    public:
        virtual bool OnInit();
        virtual int OnExit();

};

#endif // BIRRAMATICAPP_H
