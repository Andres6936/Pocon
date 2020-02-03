#include "Keyboard.hpp"

Pocon::KeyCode Pocon::Keyboard::ConvertStringToKeyCode(const std::string& key)
{
	if (key == "A")
	{
		return KeyCode::K_A;
	}
	else if (key == "B")
	{
		return KeyCode::K_B;
	}
	else
	{
		return KeyCode::None;
	}
}
