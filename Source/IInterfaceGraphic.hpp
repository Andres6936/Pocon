#ifndef POCON_IINTERFACEGRAPHIC_HPP
#define POCON_IINTERFACEGRAPHIC_HPP

#include <string>
#include "Keyboard/KeyCode.hpp"

namespace Pocon
{
	class IInterfaceGraphic
	{

	public:

		virtual ~IInterfaceGraphic() = default;

		virtual void ShowMessageOfWelcome() = 0;

		virtual void ShowOptions() = 0;

		virtual KeyCode GetKeyPressed() = 0;

		virtual std::string GetFilenameFromInputUser() = 0;

		virtual std::string GetDirectoryNameFromInputUser() = 0;

	};
}

#endif //POCON_IINTERFACEGRAPHIC_HPP
