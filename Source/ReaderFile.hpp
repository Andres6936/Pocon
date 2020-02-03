#ifndef POCON_READERFILE_HPP
#define POCON_READERFILE_HPP

#include <fstream>

namespace Pocon
{
	class ReaderFile
	{

	private:

		unsigned int sizeFile = 0;

		std::string buffer;

		std::ifstream stream;

	public:

		ReaderFile() = default;

		void ReadFile(const std::string& _filename);

		// Getters

		const std::string& GetBuffer() const;

	};
}


#endif //POCON_READERFILE_HPP
