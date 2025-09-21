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

BOOL CConfigDialog::PreTranslateMessage(MSG* pMsg)
	{

	switch (pMsg->message)
		{
		case WM_KEYDOWN:
			if (pMsg->wParam == VK_SHIFT)
				{
				m_bShiftDown = true;
				}
			else if (pMsg->wParam == VK_RETURN)
				{
				CWnd* pWnd = GetFocus();
				if (pWnd)
					{
					CWnd* pNext = GetNextDlgTabItem(pWnd, m_bShiftJustReleased);
					if (pNext && pNext != pWnd)
						{
						pNext->SetFocus();

						CEdit* pEdit = (CEdit*)CEdit::FromHandle(pNext->GetSafeHwnd());
						if (pEdit)
							{
							TRACE0("EDIT");
							pEdit->SetSel(0, -1);// Select all text
							} else {TRACE0("No Edit");}
							m_bShiftJustReleased = false;
						return TRUE; // Eat Enter
						}
					}
				m_bShiftJustReleased = false;
				return TRUE;
				}
			else {
				m_bShiftJustReleased = false;
				}
			break;

		case WM_KEYUP:
			if (pMsg->wParam == VK_SHIFT)
				{
				m_bShiftDown = false;
				m_bShiftJustReleased = true;
				}
			break;
		}

	return CDialog::PreTranslateMessage(pMsg); // Default handling
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
	ON_EN_KILLFOCUS(IDC_MFP_SV_ADD, &CConfigDialog::OnEnKillfocusMfpSvAdd)
	ON_EN_KILLFOCUS(IDC_MFP_SV_PT, &CConfigDialog::OnEnKillfocusMfpSvPt)
	ON_EN_KILLFOCUS(IDC_MFP_SV_KEY, &CConfigDialog::OnEnKillfocusMfpSvKey)
	ON_EN_KILLFOCUS(IDC_GR_SV_ADD, &CConfigDialog::OnEnKillfocusGrSvAdd)
	ON_EN_KILLFOCUS(IDC_GR_SV_PT, &CConfigDialog::OnEnKillfocusGrSvPt)
	ON_EN_KILLFOCUS(IDC_GR_SV_KEY, &CConfigDialog::OnEnKillfocusGrSvKey)
	ON_EN_KILLFOCUS(IDC_API_SV_ADD, &CConfigDialog::OnEnKillfocusApiSvAdd)
	ON_EN_KILLFOCUS(IDC_API_SV_PT, &CConfigDialog::OnEnKillfocusApiSvPt)
	ON_EN_KILLFOCUS(IDC_API_SV_KEY, &CConfigDialog::OnEnKillfocusApiSvKey)
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

void CConfigDialog::OnEnKillfocusMfpSvAdd()
	{
	// TODO: Add your control notification handler code here
	}

void CConfigDialog::OnEnKillfocusMfpSvPt()
	{
	// TODO: Add your control notification handler code here
	}

void CConfigDialog::OnEnKillfocusMfpSvKey()
	{
	// TODO: Add your control notification handler code here
	}

void CConfigDialog::OnEnKillfocusGrSvAdd()
	{
	// TODO: Add your control notification handler code here
	}

void CConfigDialog::OnEnKillfocusGrSvPt()
	{
	// TODO: Add your control notification handler code here
	}

void CConfigDialog::OnEnKillfocusGrSvKey()
	{
	// TODO: Add your control notification handler code here
	}

void CConfigDialog::OnEnKillfocusApiSvAdd()
	{
	// TODO: Add your control notification handler code here
	}

void CConfigDialog::OnEnKillfocusApiSvPt()
	{
	// TODO: Add your control notification handler code here
	}

void CConfigDialog::OnEnKillfocusApiSvKey()
	{
	// TODO: Add your control notification handler code here
	}
