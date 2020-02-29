#ifndef POCON_POCON_HPP
#define POCON_POCON_HPP

#include <vector>
#include <string>
#include <filesystem>

#include "IInterfaceGraphic.hpp"
#include "CommandLine.hpp"
#include "Readable.hpp"

namespace Pocon
{
	class Pocon
	{

	private:

		IInterfaceGraphic* graphic = new CommandLine();

		Readable reader;

		std::filesystem::path filename;

		std::filesystem::path directoryName;

		std::vector <std::string> arguments;

	public:

		Pocon(int argc, char** argv);

		virtual ~Pocon();

		void Run();

		void ProcessOnlyAFile();

		void ProcessMultiplesFiles();

		bool IsArgumentsEmpty() const;

		std::string GetFilenameFromArguments() const;

		std::string GetDirectoryNameFromArguments() const;

	};
}


#endif //POCON_POCON_HPP
