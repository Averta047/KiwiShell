//============ Copyright KiwiShell, All rights reserved ============//
//
//  Purpose: 
//
//==================================================================//

#include "CInput.h"

#include <iostream>
#include <string>

CInput::CInput()
{

}

CInput::~CInput()
{

}

const char* CInput::Read(const char* message)
{
	std::string value = std::string("");

	std::cout << message;
	std::getline(std::cin, value);
	std::cout << std::endl;

	return value.c_str();
}