
// LaserFrmCLR.cpp: 定義應用程式的類別表現方式。
//

#include "pch.h"
#include "framework.h"
#include "LaserFrmCLR.h"
#include "DlgLaserFrmCLR.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLaserFrmCLRApp

BEGIN_MESSAGE_MAP(CLaserFrmCLRApp, CWinApp)
END_MESSAGE_MAP()


// CLaserFrmCLRApp 建構

CLaserFrmCLRApp::CLaserFrmCLRApp()
{
	// TODO: 在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}


// 唯一一個 CLaserFrmCLRApp 物件

CLaserFrmCLRApp theApp;


// CLaserFrmCLRApp 初始化

BOOL CLaserFrmCLRApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}


LONG_PTR FAR PASCAL CLR_CreateDialog()
{
	CDlgLaserFrmCLR* pDlg = new CDlgLaserFrmCLR;
	return (LONG_PTR)pDlg;
}


void FAR PASCAL CLR_FreeDialog(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return;

	CDlgLaserFrmCLR* pDlg = (CDlgLaserFrmCLR*)lLibPtr;
	delete pDlg;
	pDlg = NULL;
}


BOOL FAR PASCAL CLR_InitWindow(LONG_PTR lLibPtr, CWnd* pWndParent)
{
	if (!lLibPtr)
		return FALSE;

	HINSTANCE hCurInstance = AfxGetResourceHandle();
	AfxSetResourceHandle(theApp.m_hInstance);

	CDlgLaserFrmCLR* pDlg = (CDlgLaserFrmCLR*)lLibPtr;
	BOOL bRet = pDlg->InitWindow(pWndParent);

	AfxSetResourceHandle(hCurInstance);

	return bRet;
}


void FAR PASCAL CLR_ShowView(LONG_PTR lLibPtr, BOOL bShow)
{
	if (!lLibPtr)
		return;

	CDlgLaserFrmCLR* pDlg = (CDlgLaserFrmCLR*)lLibPtr;
	if (bShow)
		pDlg->ShowWindow(SW_SHOW);
	else
		pDlg->ShowWindow(SW_HIDE);
}


HWND FAR PASCAL CLR_GetHandle(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return NULL;

	CDlgLaserFrmCLR* pDlg = (CDlgLaserFrmCLR*)lLibPtr;
	return pDlg->m_hWnd;
}


BOOL FAR PASCAL CLR_InitUserControl(LONG_PTR lLibPtr, int iX, int iY, int iViewWidth, int iViewHeight)
{
	if (!lLibPtr)
		return FALSE;

	CDlgLaserFrmCLR* pDlg = (CDlgLaserFrmCLR*)lLibPtr;
	return pDlg->InitUserControl(iX, iY, iViewWidth, iViewHeight);
}


void FAR PASCAL CLR_MarkFinderShow(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return;

	CDlgLaserFrmCLR* pDlg = (CDlgLaserFrmCLR*)lLibPtr;
	pDlg->MarkFinderShow();
}
