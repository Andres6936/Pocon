#include <iostream>
#include "CommandLine.hpp"
#include "Keyboard/Keyboard.hpp"

void Pocon::CommandLine::ShowMessageOfWelcome()
{
	std::cout << "Welcome to converer of file PO to Xml.\n\n";
}

void Pocon::CommandLine::ShowOptions()
{
	std::cout << "Please Sr. Choice an option.\n\n";

	std::cout << "\tA. Convert an file.\n";
	std::cout << "\tB. Convert multiples files.\n";
}

Pocon::KeyCode Pocon::CommandLine::GetKeyPressed()
{
	std::string keyString;
	// Get key pressed for the user.
	std::cin >> keyString;

	return Keyboard::ConvertStringToKeyCode(keyString);
}

std::string Pocon::CommandLine::GetFilenameFromInputUser()
{
	std::cout << "Please Write Path to File Po.\n";

	std::string filename;
	std::cin >> filename;

	return filename;
}

std::string Pocon::CommandLine::GetDirectoryNameFromInputUser()
{
	std::cout << "Please Write Path to Directory with files Po.\n";

	std::string directoryName;
	std::cin >> directoryName;

	return directoryName;
}
