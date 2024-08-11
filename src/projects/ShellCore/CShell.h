//============ Copyright KiwiShell, All rights reserved ============//
//
//  Purpose: 
//
//==================================================================//

#pragma once



class CShell
{
public:
	CShell();
	~CShell();

public:
	const char* GetDir() { return m_pDir; }
	void SetDir(const char* dir) { m_pDir = dir; }

private:
	const char* m_pDir;
};