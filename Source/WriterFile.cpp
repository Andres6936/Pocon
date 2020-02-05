#include "WriterFile.hpp"

// Setters

void Pocon::WriterFile::SetPropertiesFile(const std::vector <PropertyFile>& _propertiesFile)
{
	propertiesFile = _propertiesFile;
}

void Pocon::WriterFile::SetLicenseFile(const std::string& _licenseFile)
{
	licenseFile = _licenseFile;
}

void Pocon::WriterFile::SetCreditsFile(const std::vector <std::string>& _creditsFile)
{
	creditsFile = _creditsFile;
}

// Construct

Pocon::WriterFile::WriterFile() = default;

// Methods

void Pocon::WriterFile::CreateFileStruct()
{
	document.LinkEndChild(new Ana::Declaration("1.0", "UTF-8", ""));

	// Write the license like comment
	document.LinkEndChild(new Ana::Comment(licenseFile.c_str()));
	// Create main element
	document.LinkEndChild(new Ana::Element("LanguageInject"));
}

void Pocon::WriterFile::SaveFileInFormatXml()
{
	document.SaveFile("Out.xml");
}

void Pocon::WriterFile::SetDictionary(const std::vector <WordTranslate>& _dictionary)
{
	dictionary = _dictionary;
}

void Pocon::WriterFile::CreateNameOfElements()
{
	for (WordTranslate& word : dictionary)
	{
		if (HaveThreeWords(word.first))
		{
			word.first = GetNameShortForAElementOfThreeWords(word.first);
		}
		else if (HaveTwoWords(word.first))
		{
			word.first = GetNameShortForAElementOfTwoWords(word.first);
		}
			// Only have an word and not is needed take actions
		else
		{
			continue;
		}
	}
}

bool Pocon::WriterFile::HaveThreeWords(std::string_view _word)
{
	unsigned int countOfWhitespace = 0;

	int positionWhiteSpace = _word.find(' ');

	if (positionWhiteSpace == std::string::npos)
	{
		return false;
	}

	while (true)
	{
		countOfWhitespace++;
		positionWhiteSpace = _word.find(' ', positionWhiteSpace);

		if (positionWhiteSpace == std::string::npos)
		{
			break;
		}

		// Advance to next white space
		positionWhiteSpace++;

		if (countOfWhitespace >= 2)
		{
			return true;
		}
	}

	return false;
}

bool Pocon::WriterFile::HaveTwoWords(std::string_view _word)
{
	int positionWhiteSpace = _word.find(' ');

	if (positionWhiteSpace == std::string::npos)
	{
		return false;
	}
	else
	{
		// An white space mean that exits more that two words.
		return true;
	}
}

std::string Pocon::WriterFile::GetNameShortForAElementOfThreeWords(std::string_view _basedIn)
{
	std::vector <std::string> var = ExtractTheThreeWordsMoreLengthOf(_basedIn);

	for (std::string& s : var)
	{
		CapitalizeTheFirstLetterOf(s);
	}

	return std::string(var[0] + var[1] + var[2]);
}

std::string Pocon::WriterFile::GetNameShortForAElementOfTwoWords(std::string_view _basedIn)
{
	std::vector <std::string> var = ExtractTheTwoWordsMoreLengthOf(_basedIn);

	for (std::string& s : var)
	{
		CapitalizeTheFirstLetterOf(s);
	}

	return std::string(var[0] + var[1]);
}

std::vector <std::string> Pocon::WriterFile::ExtractAllWordsOfAString(std::string_view _string)
{
	std::vector <std::string> wordsInString;

	int startWord = 0;
	int positionWhiteSpace = 0;

	while (true)
	{
		positionWhiteSpace = _string.find(' ', positionWhiteSpace);

		// Is necessary make the cast for use push_back
		wordsInString.push_back((std::string)_string.substr(startWord, positionWhiteSpace - startWord));

		if (positionWhiteSpace == std::string::npos)
		{
			break;
		}

		// Advance to next word.
		positionWhiteSpace++;
		// Remember the start of word
		startWord = positionWhiteSpace;
	}

	return wordsInString;
}

std::vector <std::string> Pocon::WriterFile::ExtractTheThreeWordsMoreLengthOf(std::string_view _word)
{
	std::vector <std::string> wordsInString = ExtractAllWordsOfAString(_word);

	if (wordsInString.size() > 3)
	{
		while (wordsInString.size() > 3)
		{
			DeleteTheWordMoreShortOf(wordsInString);
		}
	}

	return wordsInString;
}

std::vector <std::string> Pocon::WriterFile::ExtractTheTwoWordsMoreLengthOf(std::string_view _word)
{
	std::vector <std::string> wordsInString = ExtractAllWordsOfAString(_word);

	if (wordsInString.size() > 2)
	{
		while (wordsInString.size() > 2)
		{
			DeleteTheWordMoreShortOf(wordsInString);
		}
	}

	return wordsInString;
}

void Pocon::WriterFile::DeleteTheWordMoreShortOf(std::vector <std::string>& _vector)
{
	// We supposition, the first element is the word more short.

	unsigned int indexOfWordMoreShort = 0;
	unsigned int lengthOfWordMoreShort = _vector[0].size();

	for (int i = 1; i < _vector.size(); ++i)
	{
		if (_vector[i].size() < lengthOfWordMoreShort)
		{
			indexOfWordMoreShort = i;
			lengthOfWordMoreShort = _vector[i].size();
		}
	}

	_vector.erase(_vector.begin() + indexOfWordMoreShort);
}

void Pocon::WriterFile::CapitalizeTheFirstLetterOf(std::string& _string)
{
	_string[0] = std::toupper(_string[0]);
}

void Pocon::WriterFile::CreateElementsAndTranslates()
{
	// Get the last element added in the document,
	// it last element must be a Element called LanguageInject,
	// from this point, we must be added all elements that is
	// in the dictionary.
	auto var = document.LastChild();

	for (const WordTranslate& word : dictionary)
	{
		auto element = new Ana::Element(word.first);
		element->LinkEndChild(new Ana::Text(word.second));
		var->LinkEndChild(element);
	}
}
