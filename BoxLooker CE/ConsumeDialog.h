#pragma once
#include <vector>
// CConsumeDialog dialog

class CConsumeDialog : public CDialog
	{
	DECLARE_DYNAMIC(CConsumeDialog)

	public:
		CConsumeDialog(CWnd* pParent = NULL);   // standard constructor
		CConsumeDialog(UINT nIDTemplate, CWnd* pParent = NULL);
		BOOL OnInitDialog();
		virtual ~CConsumeDialog();

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
