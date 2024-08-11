//============ Copyright KiwiShell, All rights reserved ============//
//
//  Purpose: 
//
//==================================================================//

#include "CConsole.h"

#include <windows.h>
#include <iostream>
#include <cstdarg>

CConsole::CConsole()
{
}

CConsole::~CConsole()
{
}

void CConsole::Print(const char* arg, ...)
{
    va_list args;
    va_start(args, arg);
    vprintf(arg, args);
    va_end(args);
}

void CConsole::Clear()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 }; // top-left corner
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hConsole, &bufferInfo);
    DWORD cells = bufferInfo.dwSize.X * bufferInfo.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, ' ', cells, coord, &written);
    GetConsoleScreenBufferInfo(hConsole, &bufferInfo);
    FillConsoleOutputAttribute(hConsole, bufferInfo.wAttributes, cells, coord, &written);
    SetConsoleCursorPosition(hConsole, coord);
}
