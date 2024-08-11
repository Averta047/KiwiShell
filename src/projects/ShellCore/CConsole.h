//============ Copyright KiwiShell, All rights reserved ============//
//
//  Purpose: 
//
//==================================================================//

#pragma once

#include <vector>

class CConsole
{
public:
	CConsole();
	~CConsole();

public:
	void Print(const char* arg, ...);
	void Clear();
};