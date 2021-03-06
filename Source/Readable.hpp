#ifndef POCON_READABLE_HPP
#define POCON_READABLE_HPP

#include <fstream>
#include <filesystem>

namespace Pocon
{
	class Readable
	{

	private:

		unsigned int sizeFile = 0;

		std::string buffer;

		std::ifstream stream;

	public:

		Readable() = default;

		void ReadFile(const std::filesystem::path& _filename);

		// Getters

		const std::string& GetBuffer() const;

	};
}


#endif //POCON_READABLE_HPP
