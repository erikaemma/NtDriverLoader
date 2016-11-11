// NtDriverLoader.h : main header file for the NTDRIVERLOADER application
//

#if !defined(AFX_NTDRIVERLOADER_H__D545FBB8_E6E4_4B11_9813_99F0C0B78C3C__INCLUDED_)
#define AFX_NTDRIVERLOADER_H__D545FBB8_E6E4_4B11_9813_99F0C0B78C3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNtDriverLoaderApp:
// See NtDriverLoader.cpp for the implementation of this class
//

class CNtDriverLoaderApp : public CWinApp
{
public:
	CNtDriverLoaderApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNtDriverLoaderApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNtDriverLoaderApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NTDRIVERLOADER_H__D545FBB8_E6E4_4B11_9813_99F0C0B78C3C__INCLUDED_)
