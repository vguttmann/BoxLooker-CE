// BoxLooker CE.h : main header file for the BoxLooker CE application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

// CBoxLookerCEApp:
// See BoxLooker CE.cpp for the implementation of this class
//

class CBoxLookerCEApp : public CWinApp
{
public:
	CBoxLookerCEApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
public:
	afx_msg void OnAppAbout();
	afx_msg void OnAppGithub();
	afx_msg void OnAppManual();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPreferencesGrocyconnection();
	afx_msg void OnPreferencesApiconnection();
	afx_msg void OnPreferencesMyfitnesspalconnection();
	};

extern CBoxLookerCEApp theApp;
