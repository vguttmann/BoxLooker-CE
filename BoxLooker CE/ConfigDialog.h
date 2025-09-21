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
	BOOL PreTranslateMessage(MSG* pMsg);
	CCommandBar m_wndCommandBar;
	CFont m_HeaderFont;
	bool m_bShiftDown;
	bool m_bShiftJustReleased;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnSave();
	afx_msg void OnDiscard();
	afx_msg void OnEnKillfocusMfpSvAdd();
	afx_msg void OnEnKillfocusMfpSvPt();
	afx_msg void OnEnKillfocusMfpSvKey();
	afx_msg void OnEnKillfocusGrSvAdd();
	afx_msg void OnEnKillfocusGrSvPt();
	afx_msg void OnEnKillfocusGrSvKey();
	afx_msg void OnEnKillfocusApiSvAdd();
	afx_msg void OnEnKillfocusApiSvPt();
	afx_msg void OnEnKillfocusApiSvKey();
	};
