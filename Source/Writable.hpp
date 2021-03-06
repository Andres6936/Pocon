#ifndef POCON_WRITABLE_HPP
#define POCON_WRITABLE_HPP

#include "Ana/Ana.hpp"

#include <string>
#include <vector>
#include <string_view>

namespace Pocon
{
	// First = Origin String
	// Second = Translate String of Origin
	using WordTranslate = std::pair <std::string, std::string>;

	// First = Name Property
	// Second = Value of Property
	using PropertyFile = std::pair <std::string, std::string>;

	class Writable
	{

	private:

		std::string licenseFile;

		std::vector <std::string> creditsFile;

		std::vector <WordTranslate> dictionary;

		std::vector <PropertyFile> propertiesFile;

		Ana::Document document;

		static void FormatStringToCapitalize(std::string& _string);

		static void CapitalizeTheFirstLetterOf(std::string& _string);

		static void DeleteTheWordMoreShortOf(std::vector <std::string>& _vector);

		static bool HaveXWords(unsigned int x, std::string_view _string);

		static bool HaveFourWords(std::string_view _word);

		static bool HaveThreeWords(std::string_view _word);

		static bool HaveTwoWords(std::string_view _word);

		static std::string GetNameShortForAElementOfFourWords(std::string_view _basedIn);

		static std::string GetNameShortForAElementOfThreeWords(std::string_view _basedIn);

		static std::string GetNameShortForAElementOfTwoWords(std::string_view _basedIn);

		static std::vector <std::string> ExtractAllWordsOfAString(std::string_view _string);

		static std::vector <std::string> ExtractTheXWordsMoreLengthOf(std::string_view _word, unsigned int x);

		static std::vector <std::string> ExtractTheFourWordsMoreLengthOf(std::string_view _word);

		static std::vector <std::string> ExtractTheThreeWordsMoreLengthOf(std::string_view _word);

		static std::vector <std::string> ExtractTheTwoWordsMoreLengthOf(std::string_view _word);

	public:

		// Construct

		Writable();

		// Methods

		void CreateFileStruct();

		void CreateNameOfElements();

		void CreateElementsAndTranslates();

		void SaveFileInFormatXml(std::string_view _filenameOutput);

		// Setters

		void SetLicenseFile(const std::string& _licenseFile);

		void SetCreditsFile(const std::vector <std::string>& _creditsFile);

		void SetDictionary(const std::vector <WordTranslate>& _dictionary);

		void SetPropertiesFile(const std::vector <PropertyFile>& _propertiesFile);

	};
}


#endif //POCON_WRITABLE_HPP
