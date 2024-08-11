//============ Copyright KiwiShell, All rights reserved ============//
//
//  Purpose: 
//
//==================================================================//

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <string>

#include "CConsole.h"
#include "Global.h"

void FnHelp(const char* param)
{
	//std::cout << "param : " << param << std::endl;
	std::cout << "help called" << std::endl;
}

int main()
{
	std::cout << "KiwiShell started [Build: " << __DATE__ << "]\n" << std::endl;

	std::string line;
	while (true) 
	{
		std::string arg_line = std::string("");
		std::cout << G.strDirectory << ">";
		std::getline(std::cin, arg_line);
		std::cout << std::endl;

		if (arg_line == "EXIT")
		{
			std::cout << "> KiwiShell exited." << std::endl;
			return EXIT_SUCCESS;
		}
		else if (arg_line == "HELP")
		{

		}
		else if (arg_line.rfind("dir ", 0) == 0)
		{
			G.strDirectory = arg_line.substr(arg_line.find(' ') + 1);
		}
		else
		{
			std::cout << "Unknown command or syntax: (" << arg_line << ")" << std::endl;
		}
	}

	return EXIT_SUCCESS;
}