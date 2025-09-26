// CDialogConsume.cpp : implementation file
//

#include "stdafx.h"
#include "BoxLooker CE.h"
#include "CDialogConsume.h"
#include <vector>


// CDialogConsume dialog

IMPLEMENT_DYNAMIC(CDialogConsume, CDialog)

CDialogConsume::CDialogConsume(CWnd* pParent /*=NULL*/)
: CDialog(CDialogConsume::IDD, pParent)
	{

	}

CDialogConsume::CDialogConsume(UINT nIDTemplate, CWnd* pParent)
: CDialog(nIDTemplate, pParent)
	{

	}

CDialogConsume::~CDialogConsume()
	{
	}

BOOL CDialogConsume::PreTranslateMessage(MSG* pMsg)
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

std::vector<UINT> CDialogConsume::GetAllEditControls()
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


BOOL CDialogConsume::OnInitDialog()
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
	return TRUE;
	}

void CDialogConsume::DoDataExchange(CDataExchange* pDX)
	{
	CDialog::DoDataExchange(pDX);
	}


BEGIN_MESSAGE_MAP(CDialogConsume, CDialog)
	ON_COMMAND(IDC_CON_EAN_GO, &CDialogConsume::OnGo)
	ON_EN_KILLFOCUS(IDC_CON_EAN, &CDialogConsume::OnEnKillfocusEAN)
END_MESSAGE_MAP()


void CDialogConsume::OnGo()
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

void CDialogConsume::OnEnKillfocusEAN()
	{
	// TODO: Add your control notification handler code here
	}


// CDialogConsume message handlers
