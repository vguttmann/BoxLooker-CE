#pragma once



class CDialogConsume : public CDialog
{
	DECLARE_DYNAMIC(CDialogConsume)

public:
	CDialogConsume(CWnd* pParent = NULL);   // standard constructor
	CDialogConsume(UINT nIDTemplate, CWnd* pParent = NULL);
	BOOL OnInitDialog();
	virtual ~CDialogConsume();

// Dialog Data
	enum { IDD = IDD_CONSUME };

protected:
	std::vector<UINT> GetAllEditControls();
	BOOL PreTranslateMessage(MSG* pMsg);
	CFont m_HeaderFont;
	bool m_bShiftDown;
	bool m_bShiftJustReleased;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnGo();
	afx_msg void OnEnKillfocusEAN();

};
