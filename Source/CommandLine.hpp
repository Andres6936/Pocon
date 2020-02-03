#ifndef POCON_COMMANDLINE_HPP
#define POCON_COMMANDLINE_HPP

#include "IInterfaceGraphic.hpp"

namespace Pocon
{
	class CommandLine : public IInterfaceGraphic
	{

	private:

	public:

		void ShowMessageOfWelcome() override;

		void ShowOptions() override;

		KeyCode GetKeyPressed() override;

		std::string GetFilenameFromInputUser() override;

		std::string GetDirectoryNameFromInputUser() override;

	};
}


#endif //POCON_COMMANDLINE_HPP
