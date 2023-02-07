// UserControlCLR.h: UserControlCLR DLL 的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 在包含此檔案前先包含 'pch.h'"
#endif

#include "resource.h"		// 主要符號


// CUserControlCLRApp
// 此類別的實作請參閱 UserControlCLR.cpp
//

class CUserControlCLRApp : public CWinApp
{
public:
	CUserControlCLRApp();

// 覆寫
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
