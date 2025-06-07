// ConfigDialog.cpp : implementation file
//

#include "stdafx.h"
#include "BoxLooker CE.h"
#include "ConfigDialog.h"
#include <vector>


// CConfigDialog dialog

IMPLEMENT_DYNAMIC(CConfigDialog, CDialog)

CConfigDialog::CConfigDialog(CWnd* pParent /*=NULL*/)
: CDialog(CConfigDialog::IDD, pParent)
	{

	}

CConfigDialog::CConfigDialog(UINT nIDTemplate, CWnd* pParent)
: CDialog(nIDTemplate, pParent)
	{

	}

CConfigDialog::~CConfigDialog()
	{
	}

std::vector<UINT> CConfigDialog::GetAllEditControls()
	{
	std::vector<UINT> editIDs;

	CWnd* pChild = GetWindow(GW_CHILD);
	while (pChild)
		{
		TCHAR className[32] = {0};
		::GetClassName(pChild->GetSafeHwnd(), className, _countof(className));

		if (_tcscmp(className, _T("Edit")) == 0)
			{
			UINT ctrlID = pChild->GetDlgCtrlID();
			if (ctrlID != 0)  // 0 means no ID (may be a dynamic or unnamed control)
				{
				editIDs.push_back(ctrlID);
				}
			}
		pChild = pChild->GetNextWindow();
		}
	return editIDs;
	}


BOOL CConfigDialog::OnInitDialog()
	{
	CDialog::OnInitDialog();
	// GetProfileString("V1", memberIDD, NULL);
	CWinApp *pApp = AfxGetApp();
	m_HeaderFont.CreateFont(
		20,                        // Height (in logical units)
		0,                         // Width
		0,                         // Escapement
		0,                         // Orientation
		FW_BOLD,                   // Weight
		FALSE,                     // Italic
		FALSE,                     // Underline
		0,                         // StrikeOut
		ANSI_CHARSET,              // CharSet
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,  // PitchAndFamily
		_T("MS Sans Serif")             // Font name
		);

	// Apply font to the control
	CWnd* pHeader = GetDlgItem(IDC_DIALOG_TITLE);
	if (pHeader != NULL)
		pHeader->SetFont(&m_HeaderFont);


	std::vector<UINT> editControls = GetAllEditControls();

	for(size_t i = 0; i < editControls.size(); i++){
		CString id;
		id.Format(_T("%d"), editControls[i]);
		CString defaultValue = pApp->GetProfileString(_T("V1"), id, NULL);
		SetDlgItemText(editControls[i], defaultValue);
		}

	if (!m_wndCommandBar.Create(this) ||
		!m_wndCommandBar.InsertMenuBar(IDR_CONFIGMENU)	)
		{
		TRACE0("Failed to create CommandBar\n");
		return -1;      // fail to create
		}
	m_wndCommandBar.SetBarStyle(m_wndCommandBar.GetBarStyle() | CBRS_SIZE_FIXED);


	return TRUE;
	}

void CConfigDialog::DoDataExchange(CDataExchange* pDX)
	{
	CDialog::DoDataExchange(pDX);
	}


BEGIN_MESSAGE_MAP(CConfigDialog, CDialog)
	ON_COMMAND(ID_SAVE, &CConfigDialog::OnSave)
	ON_COMMAND(ID_DISCARD, &CConfigDialog::OnDiscard)
END_MESSAGE_MAP()

void CConfigDialog::OnSave()
	{
	CWinApp *pApp = AfxGetApp();
	std::vector<UINT> editControls = GetAllEditControls();

	for(size_t i = 0; i < editControls.size(); i++){
		CString id;
		id.Format(_T("%d"), editControls[i]);
		CString text;
		GetDlgItemText(editControls[i], text);
		TRACE(text);
		TRACE0("\n");
		pApp->WriteProfileString(_T("V1"), id, text);
		}
	EndDialog(0);
	}

void CConfigDialog::OnDiscard()
	{
	EndDialog(0);
	}

// CConfigDialog message handlers
