#ifndef POCON_XML_HPP
#define POCON_XML_HPP

#include <vector>
#include <string>
#include <filesystem>
#include <string_view>

#include "Readable.hpp"

namespace Pocon
{

	// First = Origin String
	// Second = Translate String of Origin
	using WordTranslate = std::pair <std::string, std::string>;

	// First = Name Property
	// Second = Value of Property
	using PropertyFile = std::pair <std::string, std::string>;

	class Xml : private Readable
	{

	private:

		static void ClearDictionaryOfTagsUnused(std::vector <WordTranslate>& _dictionary);

		static void ClearDictionaryOfTagsAndWordsEmpty(std::vector <WordTranslate>& _dictionary);

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

		static void ClearStringOfAsterisk(std::string& _string);

		static void ClearStringOfComma(std::string& _string);

		static void ClearStringOfColon(std::string& _string);

		static void FormatLicenseAddNewLine(std::string& _license);

		static void RemoveCommentsOfBufferInFirstLine(std::string& _buffer);

		static void RemoveCommentsOfBuffer(std::string& _buffer);

		static void RemoveCharInString(std::string& _string, char _char);

		static void RemoveStringInString(std::string& _string, const std::string& _coincidence);

		/**
		 * Extract a possible name (based in the translate) for the file of
		 * output, if this name not is possible determine use the pattern:
		 * Unknown{Y}.xml, where Y represent the amount of files unknowns
		 *
		 * @note Actually, the method support names unknown to SHORT_MAX (+- 32.000).
		 *  If the amount of unknown files over this limit, will be produced a
		 *  overflow and the counter begin from 0, with the consequences of
		 *  overwrite files already processed.
		 *
		 * @param _buffer Generally the buffer that content the comments
		 *  with meta-information, use for extract an name adequate for
		 *  the file of output.
		 *
		 * @return Name of file output, if no is possible determine,
		 *  return Unknown{1 - 32.000}.xml
		 */
		static std::string ExtractFilenameOutput(std::string_view _buffer);

		static std::string ExtractLicenseOfFile(std::vector <WordTranslate>& _dictionary);

		static std::vector <std::string> ExtractTranslatorCreditsOfFile(std::vector <WordTranslate>& _dictionary);

		static std::vector <PropertyFile> ExtractPropertiesOfFile(std::vector <WordTranslate>& _dictionary);

	public:

		void ConvertBufferToXml(const std::filesystem::path& filename);

	};
}


#endif //POCON_XML_HPP
