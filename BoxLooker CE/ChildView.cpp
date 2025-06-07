// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "BoxLooker CE.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_UPDATE_COMMAND_UI(ID_APPLICATION_DATAENTRYMODE, &CChildView::OnUpdateApplicationDataentrymode)
	ON_UPDATE_COMMAND_UI(ID_APPLICATION_CONSUMPTIONMODE, &CChildView::OnUpdateApplicationConsumptionmode)
	ON_UPDATE_COMMAND_UI(ID_APPLICATION_RESTOCKMODE, &CChildView::OnUpdateApplicationRestockmode)
	ON_UPDATE_COMMAND_UI(ID_APPLICATION_BAKINGMODE, &CChildView::OnUpdateApplicationBakingmode)
	ON_COMMAND(ID_APPLICATION_CONSUMPTIONMODE, &CChildView::OnApplicationConsumptionmode)
	ON_COMMAND(ID_APPLICATION_RESTOCKMODE, &CChildView::OnApplicationRestockmode)
	ON_COMMAND(ID_APPLICATION_BAKINGMODE, &CChildView::OnApplicationBakingmode)
	ON_COMMAND(ID_APPLICATION_DATAENTRYMODE, &CChildView::OnApplicationDataentrymode)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;
	m_nMode = 1;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc (this);
	CRect rect;

	GetClientRect (&rect);

	dc.DrawText (_T("Hello World!"), -1 , &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

}

void CChildView::OnUpdateApplicationConsumptionmode(CCmdUI *pCmdUI)
	{
	TRACE0("Consumption Mode UI!\n");
	pCmdUI->SetCheck (m_nMode == 1);
	}

void CChildView::OnUpdateApplicationRestockmode(CCmdUI *pCmdUI)
	{
	TRACE0("Restock Mode UI!\n");
	pCmdUI->SetCheck (m_nMode == 2);
	}

void CChildView::OnUpdateApplicationBakingmode(CCmdUI *pCmdUI)
	{
	TRACE0("Baking Mode UI!\n");
	pCmdUI->SetCheck (m_nMode == 3);
	}

void CChildView::OnUpdateApplicationDataentrymode(CCmdUI *pCmdUI)
	{
	TRACE0("Data Mode UI!\n");
	pCmdUI->SetCheck (m_nMode == 4);
	}

void CChildView::OnApplicationConsumptionmode()
	{
	TRACE0("Consumption Mode Handler!\n");
	m_nMode = 1;
	Invalidate();
	}

void CChildView::OnApplicationRestockmode()
	{
	TRACE0("Restock Mode Handler!\n");
	m_nMode = 2;
	Invalidate();
	}

void CChildView::OnApplicationBakingmode()
	{
	TRACE0("Baking Mode Handler!\n");
	m_nMode = 3;
	Invalidate();
	}

void CChildView::OnApplicationDataentrymode()
	{
	TRACE0("Data Mode Handler!\n");
	m_nMode = 4;
	Invalidate();
	}
