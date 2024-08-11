//============ Copyright KiwiShell, All rights reserved ============//
//
//  Purpose: 
//
//==================================================================//

#include "CCommand.h"

#include <Windows.h>

CCommand::CCommand()
{
    m_Commands = { };
}

CCommand::~CCommand()
{
    
}

bool CCommand::RegisterCommand(const char* command, const char* description, CommandFunc func)
{
    if (DoesCommandExist(command)) {
        MessageBox(NULL, "already defined", command, MB_OK | MB_ICONERROR);
        return false;
    }

    CommandData cmdData{ command, description, func };
    m_Commands.push_back(cmdData);
    return true;
}

bool CCommand::UnregisterCommand(const char* command)
{
    auto new_end = std::remove_if(m_Commands.begin(), m_Commands.end(),
        [command](const CommandData& item) {
            return std::strcmp(item.m_pCommand, command) == 0;
        });

    m_Commands.erase(new_end, m_Commands.end());

    return true;
}

bool CCommand::ExecuteCommandLine(const char* command_line)
{
    // step 1: check if command_line is valid
    // step 2: remove uneeded spaces. eg: "   echo    hello world  " > "echo hello world"
    // step 3: separate the first word (command) and the rest part of the string (paramaters)
    // step 4: push both command and paramaters to ExecuteCommand

    for (const auto& cmd : m_Commands)
    {
        if (strcmp(cmd.m_pCommand, command_line) == 0)
        {
            ExecuteCommand(cmd, nullptr /*temp*/);
            return true;
        }
    }

    return false;
}

bool CCommand::ExecuteCommand(const CommandData& command_data, const char* parameters)
{
    // step 1: double check if the command and parameters are valid (paramaters are optional)
    // step 2: use a searched function and find the function pointer based on command name
    // step 3: call the function and push the paramaters to the function
    // note: later the registered function will handle the paramaters if needed and use it for whatever purpose

    if (command_data.m_pFunc)
    {
        command_data.m_pFunc(parameters); // Call the function with parameters
    }

    return true;
}

bool CCommand::DoesCommandExist(const char* command)
{
    if (m_Commands.empty())
        return false;

    for (int i = 0; i < m_Commands.size(); i++)
    {
        if (strcmp(command, m_Commands[i].m_pCommand) == 0)
            return true;
    }

    return false;
}