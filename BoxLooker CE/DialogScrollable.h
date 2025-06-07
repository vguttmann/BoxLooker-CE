#pragma once


// CDialogScrollable dialog

class CDialogScrollable : public CDialog
{
	DECLARE_DYNAMIC(CDialogScrollable)

public:
	CDialogScrollable(CWnd* pParent = NULL);   // standard constructor
	CDialogScrollable(UINT nIDTemplate, CWnd* pParent = NULL);
	BOOL OnInitDialog();
	virtual ~CDialogScrollable();

// Dialog Data
	enum { IDD = IDD_DIALOGSCROLLABLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CFont m_HeaderFont;
	DECLARE_MESSAGE_MAP()
};
