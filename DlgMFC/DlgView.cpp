// DlgView.cpp: 實作檔案
//

#include "pch.h"
#include "DlgMFC.h"
#include "DlgView.h"
#include "afxdialogex.h"


// CDlgView 對話方塊

IMPLEMENT_DYNAMIC(CDlgView, CDialog)

CDlgView::CDlgView(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_VIEW, pParent)
{

}

CDlgView::~CDlgView()
{
}

void CDlgView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgView, CDialog)
END_MESSAGE_MAP()


// CDlgView 訊息處理常式

BOOL CDlgView::InitWindow(CRect rectPage, CWnd *pParent, HWND hCLRDisplayWnd)
{
	if (!m_hWnd)
	{
		if (!this->Create(IDD_DIALOG_VIEW, pParent))
			return FALSE;
	}

	::SetParent(hCLRDisplayWnd, this->m_hWnd);

	CWnd * pCWnd;
	pCWnd = FromHandle(hCLRDisplayWnd);
	pCWnd->ShowWindow(SW_SHOW);

	MoveWindow(rectPage);
	ShowWindow(SW_SHOW);

	return TRUE;
}
