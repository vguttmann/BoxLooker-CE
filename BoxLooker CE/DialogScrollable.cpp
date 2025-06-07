// DialogScrollable.cpp : implementation file
//

#include "stdafx.h"
#include "BoxLooker CE.h"
#include "DialogScrollable.h"


// CDialogScrollable dialog

IMPLEMENT_DYNAMIC(CDialogScrollable, CDialog)

CDialogScrollable::CDialogScrollable(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogScrollable::IDD, pParent)
{

}

CDialogScrollable::CDialogScrollable(UINT nIDTemplate, CWnd* pParent)
    : CDialog(nIDTemplate, pParent)
{

}

CDialogScrollable::~CDialogScrollable()
{
}

BOOL CDialogScrollable::OnInitDialog()
{
    CDialog::OnInitDialog();
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

    return TRUE;
}


void CDialogScrollable::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogScrollable, CDialog)
END_MESSAGE_MAP()


// CDialogScrollable message handlers
