#ifndef POCON_KEYBOARD_HPP
#define POCON_KEYBOARD_HPP

#include <string>
#include "KeyCode.hpp"

namespace Pocon
{
	class Keyboard
	{

	private:

	public:

		[[nodiscard]] static KeyCode ConvertStringToKeyCode(const std::string& key);

	};
}


#endif //POCON_KEYBOARD_HPP
