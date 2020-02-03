#include "ReaderFile.hpp"
#include "FileNotFoundException.hpp"

void Pocon::ReaderFile::ReadFile(const std::string& _filename)
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

		// TODO: ¿Use of std::move?
		buffer = std::string(bufferChar);

		stream.close();

		delete[] bufferChar;
	}
	else
	{
		throw FileNotFoundException("Cannot Open the File: " + _filename);
	}
}

const std::string& Pocon::ReaderFile::GetBuffer() const
{
	return buffer;
}
