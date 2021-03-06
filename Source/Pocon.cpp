#include "Pocon.hpp"
#include "Exception.hpp"
#include "Xml.hpp"

Pocon::Pocon::Pocon(int argc, char** argv)
{
	for (int i = 0; i < argc; ++i)
	{
		arguments.emplace_back(argv[i]);
	}
}

void Pocon::Pocon::Run()
{
	// Depend the conversion of input of user
	if (IsArgumentsEmpty())
	{
		graphic->ShowMessageOfWelcome();
		graphic->ShowOptions();
		KeyCode key = graphic->GetKeyPressed();

		if (key == KeyCode::K_A)
		{
			filename = graphic->GetFilenameFromInputUser();
		}
		else if (key == KeyCode::K_B)
		{
			directoryName = graphic->GetDirectoryNameFromInputUser();
		}
		else
		{
			throw Exception("NullKeyCodeException");
		}
	}
	else
	{
		// Depend the conversion of arguments of program
		filename = GetFilenameFromArguments();
		directoryName = GetDirectoryNameFromArguments();

		if (filename.string() == "None" and directoryName.string() == "None")
		{
			throw Exception("ArgumentsProgramInvalidException");
		}
	}

	// In this point, filename or directoryName must
	// be have an string different of none.

	ProcessOnlyAFile();
	ProcessMultiplesFiles();
}

Pocon::Pocon::~Pocon()
{
	delete graphic;
}

bool Pocon::Pocon::IsArgumentsEmpty() const
{
	// The only argument always present
	// is the path to file Main.cpp
	return arguments.size() == 1;
}

std::string Pocon::Pocon::GetFilenameFromArguments() const
{
	for (const std::string& argument : arguments)
	{
		int position = argument.find('=');

		if (position == std::string::npos)
		{
			continue;
		}
		else
		{
			if (argument.substr(0, position) == "filename")
			{
				return argument.substr(position + 1);
			}
		}
	}

	return "None";
}

std::string Pocon::Pocon::GetDirectoryNameFromArguments() const
{
	for (const std::string& argument : arguments)
	{
		int position = argument.find('=');

		if (position == std::string::npos)
		{
			continue;
		}
		else
		{
			if (argument.substr(0, position) == "directory")
			{
				return argument.substr(position + 1);
			}
		}
	}

	return "None";
}

void Pocon::Pocon::ProcessOnlyAFile()
{
	if (filename.string() == "None")
	{
		return;
	}
	else
	{
		// Create an anonymous object
		Xml().ConvertBufferToXml(filename);
	}
}

void Pocon::Pocon::ProcessMultiplesFiles()
{
	if (std::filesystem::exists(directoryName))
	{
		FillListWithFilenames();

		for (const std::filesystem::path& _filename : listFilenames)
		{
			Xml().ConvertBufferToXml(_filename);
		}
	}
	else
	{
		return;
	}
}

void Pocon::Pocon::FillListWithFilenames()
{
	using namespace std::filesystem;

	for (const directory_entry& entry : directory_iterator(directoryName))
	{
		if (entry.path().extension() == ".po")
		{
			listFilenames.emplace_back(entry.path());
		}
	}
}
