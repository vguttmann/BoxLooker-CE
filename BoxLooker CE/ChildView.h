// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	int m_nMode;
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnUpdateApplicationDataentrymode(CCmdUI *pCmdUI);
	afx_msg void OnUpdateApplicationConsumptionmode(CCmdUI *pCmdUI);
	afx_msg void OnUpdateApplicationRestockmode(CCmdUI *pCmdUI);
	afx_msg void OnUpdateApplicationBakingmode(CCmdUI *pCmdUI);
	afx_msg void OnApplicationConsumptionmode();
	afx_msg void OnApplicationRestockmode();
	afx_msg void OnApplicationBakingmode();
	afx_msg void OnApplicationDataentrymode();
	};

