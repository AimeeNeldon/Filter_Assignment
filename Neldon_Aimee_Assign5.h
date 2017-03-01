
// Neldon_Aimee_Assign5.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CNeldon_Aimee_Assign5App:
// See Neldon_Aimee_Assign5.cpp for the implementation of this class
//

class CNeldon_Aimee_Assign5App : public CWinApp
{
public:
	CNeldon_Aimee_Assign5App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CNeldon_Aimee_Assign5App theApp;