#ifndef POCON_XML_HPP
#define POCON_XML_HPP

#include <vector>
#include <string>

#include "ReaderFile.hpp"

namespace Pocon
{

	// First = Origin String
	// Second = Translate String of Origin
	using WordTranslate = std::pair <std::string, std::string>;

	// First = Name Property
	// Second = Value of Property
	using PropertyFile = std::pair <std::string, std::string>;

	class Xml
	{

	private:

		static void ClearDictionaryOfTagsUnused(std::vector <WordTranslate>& _dictionary);

		static void ClearWordOfTagsUnused(WordTranslate& _word);

		static void RemoveCharInString(std::string& _string, char _char);

		static void RemoveStringInString(std::string& _string, const std::string& _coincidence);

		static std::string ExtractLicenseOfFile(std::vector <WordTranslate>& _dictionary);

		static std::vector <std::string> ExtractTranslatorCreditsOfFile(std::vector <WordTranslate>& _dictionary);

		static std::vector <PropertyFile> ExtractPropertiesOfFile(std::vector <WordTranslate>& _dictionary);

	public:

		static void ConvertBufferToXml(const ReaderFile& reader);

	};
}


#endif //POCON_XML_HPP
