// UserControlCLR.cpp: 定義 DLL 的初始化常式。
//

#include "pch.h"
#include "framework.h"
#include "UserControlCLR.h"
#include "DlgUserControlCLR.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  如果這個 DLL 是動態地對 MFC DLL 連結，
//		那麼從這個 DLL 匯出的任何會呼叫
//		MFC 內部的函式，都必須在函式一開頭加上 AFX_MANAGE_STATE
//		巨集。
//
//		例如: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此處為正常函式主體
//		}
//
//		這個巨集一定要出現在每一個
//		函式中，才能夠呼叫 MFC 的內部。這意味著
//		其必須是函式內的第一個陳述式
//		，甚至必須在任何物件變數宣告前面
//		，因為它們的建構函式可能會產生對 MFC
//		DLL 內部的呼叫。
//
//		請參閱 MFC 技術提示 33 和 58 中的
//		詳細資料。
//

// CUserControlCLRApp

BEGIN_MESSAGE_MAP(CUserControlCLRApp, CWinApp)
END_MESSAGE_MAP()


// CUserControlCLRApp 建構

CUserControlCLRApp::CUserControlCLRApp()
{
	// TODO:  在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}


// 唯一一個 CUserControlCLRApp 物件

CUserControlCLRApp theApp;


// CUserControlCLRApp 初始化

BOOL CUserControlCLRApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}


LONG_PTR FAR PASCAL CLR_CreateDialog()
{
	CDlgUserControlCLR *pDlg = new CDlgUserControlCLR;
	return (LONG_PTR)pDlg;
}


void FAR PASCAL CLR_FreeDialog(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return;

	CDlgUserControlCLR *pDlg = (CDlgUserControlCLR*)lLibPtr;
	delete pDlg;
	pDlg = NULL;
}


BOOL FAR PASCAL CLR_InitWindow(LONG_PTR lLibPtr, CWnd *pWndParent)
{
	if (!lLibPtr)
		return FALSE;

	HINSTANCE hCurInstance = AfxGetResourceHandle();
	AfxSetResourceHandle(theApp.m_hInstance);

	CDlgUserControlCLR *pDlg = (CDlgUserControlCLR*)lLibPtr;
	BOOL bRet = pDlg->InitWindow(pWndParent);

	AfxSetResourceHandle(hCurInstance);

	return bRet;
}


void FAR PASCAL CLR_ShowView(LONG_PTR lLibPtr, BOOL bShow)
{
	if (!lLibPtr)
		return;

	CDlgUserControlCLR *pDlg = (CDlgUserControlCLR*)lLibPtr;
	if (bShow)
		pDlg->ShowWindow(SW_SHOW);
	else
		pDlg->ShowWindow(SW_HIDE);
}


HWND FAR PASCAL CLR_GetHandle(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return NULL;

	CDlgUserControlCLR *pDlg = (CDlgUserControlCLR*)lLibPtr;
	return pDlg->m_hWnd;
}


BOOL FAR PASCAL CLR_InitUserControl(LONG_PTR lLibPtr, int iX, int iY, int iViewWidth, int iViewHeight)
{
	if (!lLibPtr)
		return FALSE;

	CDlgUserControlCLR *pDlg = (CDlgUserControlCLR*)lLibPtr;
	return pDlg->InitUserControl(iX, iY, iViewWidth, iViewHeight);
}


void FAR PASCAL CLR_ChangeBtnToGreen(LONG_PTR lLibPtr)
{
	CDlgUserControlCLR* pDlg = (CDlgUserControlCLR*)lLibPtr;
	pDlg->ChangeBtnToGreen();
}


void FAR PASCAL CLR_ChangeBtnToRed(LONG_PTR lLibPtr)
{
	CDlgUserControlCLR* pDlg = (CDlgUserControlCLR*)lLibPtr;
	pDlg->ChangeBtnToRed();
}


void FAR PASCAL CLR_SetCallBackFunction(LONG_PTR lLibPtr, LONG_PTR func)
{
	CDlgUserControlCLR* pDlg = (CDlgUserControlCLR*)lLibPtr;
	pDlg->SetCallBackFunction((CB_FUNCTION)func);
}
