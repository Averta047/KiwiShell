//============ Copyright KiwiShell, All rights reserved ============//
//
//  Purpose: 
//
//==================================================================//

#pragma once

#include <vector>

using CommandFunc = void(*)(const char*);
class CCommand
{
private:
	struct CommandData
	{
		const char* m_pCommand;
		const char* m_pDescription;
		CommandFunc m_pFunc; // Change the type of m_pFunc
	};
	
public:
	CCommand();
	~CCommand();

public:
	bool RegisterCommand(const char* command, const char* description, CommandFunc func);
	bool UnregisterCommand(const char* command);

	bool ExecuteCommandLine(const char* command_line);
	bool ExecuteCommand(const CommandData& command_data, const char* parameters);

	bool DoesCommandExist(const char* command);

private:
	std::vector<CommandData> m_Commands;
};