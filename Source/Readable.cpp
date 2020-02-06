#include "Readable.hpp"
#include "FileNotFoundException.hpp"

void Pocon::Readable::ReadFile(const std::string& _filename)
{
	// open file in mode of only read
	stream.open(_filename, std::ios::in);

	if (stream.is_open())
	{
		// Retrieves the file size of the open file
		stream.seekg(0, std::ifstream::end);
		sizeFile = stream.tellg();
		stream.seekg(0, std::ifstream::beg);

		char* bufferChar = new char[sizeFile];

		stream.read(bufferChar, sizeFile);

		// Reserve the buffer for avoid unnecessary allocates
		buffer.reserve(sizeFile);

		for (int i = 0; i < sizeFile; ++i)
		{
			buffer.push_back(bufferChar[i]);
		}

		stream.close();

		delete[] bufferChar;
	}
	else
	{
		throw FileNotFoundException("Cannot Open the File: " + _filename);
	}
}

const std::string& Pocon::Readable::GetBuffer() const
{
	return buffer;
}
