#ifndef POCON_FILENOTFOUNDEXCEPTION_HPP
#define POCON_FILENOTFOUNDEXCEPTION_HPP

#include "Exception.hpp"

namespace Pocon
{
	class FileNotFoundException : public Exception
	{

	public:

		explicit FileNotFoundException(const std::string& _message) : Exception(_message)
		{
		}

		~FileNotFoundException() override = default;
	};
}

#endif //POCON_FILENOTFOUNDEXCEPTION_HPP
