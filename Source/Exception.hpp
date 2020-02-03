#ifndef POCON_EXCEPTION_HPP
#define POCON_EXCEPTION_HPP

#include <string>
#include <iostream>

namespace Pocon
{
	class Exception : public std::exception
	{

	private:

		std::string message;

	public:

		explicit Exception(const std::string& _message)
		{
			message = _message;
		}

		~Exception() override = default;

		virtual void ShowError() const
		{
			std::cout << message << "\n";
		}

	};
}

#endif //POCON_EXCEPTION_HPP
