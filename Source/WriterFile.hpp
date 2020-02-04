#ifndef POCON_WRITERFILE_HPP
#define POCON_WRITERFILE_HPP

#include "Ana/Ana.hpp"

#include <string>
#include <vector>

namespace Pocon
{
	// First = Origin String
	// Second = Translate String of Origin
	using WordTranslate = std::pair <std::string, std::string>;

	// First = Name Property
	// Second = Value of Property
	using PropertyFile = std::pair <std::string, std::string>;

	class WriterFile
	{

	private:

		std::string licenseFile;

		std::vector <std::string> creditsFile;

		std::vector <WordTranslate> dictionary;

		std::vector <PropertyFile> propertiesFile;

		Ana::Document document;

		static void DeleteTheWordMoreShortOf(std::vector <std::string>& _vector);

		static bool HaveThreeWords(const std::string& _word);

		static bool HaveTwoWords(const std::string& _word);

		static std::string GetNameShortForAElementOfThreeWords(const std::string& _basedIn);

		static std::string GetNameShortForAElementOfTwoWords(const std::string& _basedIn);

		static std::vector <std::string> ExtractAllWordsOfAString(const std::string& _string);

		static std::vector <std::string> ExtractTheThreeWordsMoreLengthOf(const std::string& _word);

		static std::vector <std::string> ExtractTheTwoWordsMoreLengthOf(const std::string& _word);

	public:

		// Construct

		WriterFile();

		// Methods

		void CreateFileStruct();

		void CreateNameOfElements();

		void SaveFileInFormatXml();

		// Setters

		void SetLicenseFile(const std::string& _licenseFile);

		void SetCreditsFile(const std::vector <std::string>& _creditsFile);

		void SetDictionary(const std::vector <WordTranslate>& _dictionary);

		void SetPropertiesFile(const std::vector <PropertyFile>& _propertiesFile);

	};
}


#endif //POCON_WRITERFILE_HPP
