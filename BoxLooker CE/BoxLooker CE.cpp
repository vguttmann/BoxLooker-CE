// BoxLooker CE.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "BoxLooker CE.h"
#include "MainFrm.h"
#include "ConfigDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBoxLookerCEApp

BEGIN_MESSAGE_MAP(CBoxLookerCEApp, CWinApp)
	ON_COMMAND(ID_ABOUTBOXLOOKERCE_ABOUTBOXLOOKERCE, &CBoxLookerCEApp::OnAppAbout)
	ON_COMMAND(ID_ABOUTBOXLOOKERCE_ONLINEMANUAL, &CBoxLookerCEApp::OnAppManual)
	ON_COMMAND(ID_ABOUTBOXLOOKERCE_GITHUB, &CBoxLookerCEApp::OnAppGithub)
	ON_COMMAND(ID_PREFERENCES_GROCYCONNECTION, &CBoxLookerCEApp::OnPreferencesGrocyconnection)
	ON_COMMAND(ID_PREFERENCES_APICONNECTION, &CBoxLookerCEApp::OnPreferencesApiconnection)
	ON_COMMAND(ID_PREFERENCES_MYFITNESSPALCONNECTION, &CBoxLookerCEApp::OnPreferencesMyfitnesspalconnection)
END_MESSAGE_MAP()



// CBoxLookerCEApp construction
CBoxLookerCEApp::CBoxLookerCEApp()
	: CWinApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CBoxLookerCEApp object
CBoxLookerCEApp theApp;

// CBoxLookerCEApp initialization

BOOL CBoxLookerCEApp::InitInstance()
{
#if defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP)
    // SHInitExtraControls should be called once during your application's initialization to initialize any
    // of the Windows Mobile specific controls such as CAPEDIT and SIPPREF.
    SHInitExtraControls();
#endif // WIN32_PLATFORM_PSPC || WIN32_PLATFORM_WFSP

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Bugfish"));
	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// create and load the frame with its resources
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL, NULL);
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

// CBoxLookerCEApp message handlers


// App command to run the dialog
void CBoxLookerCEApp::OnAppAbout()
{
	CDialog aboutDlg = CDialog(IDD_ABOUT);
	aboutDlg.DoModal();
}

void CBoxLookerCEApp::OnAppGithub()
{
	CDialog githubDlg = CDialog(IDD_GITHUB);
	githubDlg.DoModal();
}

void CBoxLookerCEApp::OnAppManual()
{
	CDialog manualDlg = CDialog(IDD_MANUAL);
	manualDlg.DoModal();
	}
void CBoxLookerCEApp::OnPreferencesGrocyconnection()
	{
	CConfigDialog grocyDlg = CConfigDialog(IDD_GROCY);
	grocyDlg.DoModal();
	}

void CBoxLookerCEApp::OnPreferencesApiconnection()
	{
	CConfigDialog apiDlg = CConfigDialog(IDD_API);
	apiDlg.DoModal();
	}

void CBoxLookerCEApp::OnPreferencesMyfitnesspalconnection()
	{
	CConfigDialog mfpDlg = CConfigDialog(IDD_MFP);
	mfpDlg.DoModal();
	}
