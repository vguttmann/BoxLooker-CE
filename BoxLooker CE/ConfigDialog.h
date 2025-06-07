#pragma once
#include <vector>
// CConfigDialog dialog

class CConfigDialog : public CDialog
{
	DECLARE_DYNAMIC(CConfigDialog)

public:
	CConfigDialog(CWnd* pParent = NULL);   // standard constructor
	CConfigDialog(UINT nIDTemplate, CWnd* pParent = NULL);
	BOOL OnInitDialog();
	virtual ~CConfigDialog();

// Dialog Data
	enum { IDD = IDD_CONFIGDIALOG };

protected:
	std::vector<UINT> GetAllEditControls();
	CCommandBar m_wndCommandBar;
	CFont m_HeaderFont;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnSave();
	afx_msg void OnDiscard();
};
