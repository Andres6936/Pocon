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

		static void ClearWordOfUnderscore(WordTranslate& _word);

		static void ClearStringOfWordsSeparatedWithHyphen(std::string& _string);

		static void ClearStringOfFormatSequences(std::string& _string);

		static void ClearStringOfVerticalLine(std::string& _string);

		static void ClearStringOfQuestionMark(std::string& _string);

		static void ClearStringOfDecimalPoint(std::string& _string);

		static void ClearStringOfParenthesis(std::string& _string);

		static void ClearStringOfNumberSign(std::string& _string);

		static void ClearStringOfApostrophe(std::string& _string);

		static void ClearStringOfDoubleLine(std::string& _string);

		static void ClearStringOfComma(std::string& _string);

		static void ClearStringOfColon(std::string& _string);

		static void RemoveCommentsOfBufferInFirstLine(std::string& _buffer);

		static void RemoveCommentsOfBuffer(std::string& _buffer);

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
