//============ Copyright KiwiShell, All rights reserved ============//
//
//  Purpose: 
//
//==================================================================//

#pragma once

class CInput
{
public:
	CInput();
	~CInput();

public:
	const char* Read(const char* message);
};