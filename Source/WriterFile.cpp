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
		if (HaveFourWords(word.first))
		{
			word.first = GetNameShortForAElementOfFourWords(word.first);
		}
		else if (HaveThreeWords(word.first))
		{
			word.first = GetNameShortForAElementOfThreeWords(word.first);
		}
		else if (HaveTwoWords(word.first))
		{
			word.first = GetNameShortForAElementOfTwoWords(word.first);
		}
			// Only have an word
		else
		{
			FormatStringToCapitalize(word.first);
		}
	}
}

bool Pocon::WriterFile::HaveXWords(unsigned int x, std::string_view _string)
{
	unsigned int countOfWhitespace = 0;

	int positionWhiteSpace = _string.find(' ');

	while (positionWhiteSpace != std::string::npos)
	{
		countOfWhitespace++;
		positionWhiteSpace = _string.find(' ', positionWhiteSpace);

		if (positionWhiteSpace == std::string::npos)
		{
			break;
		}

		// Advance to next white space
		positionWhiteSpace++;

		// Remember, I wanna determine: ¿how many words have the string?,
		// we know that normally the words of a text are separated
		// with a whitespace, for text with 2 words, the number of
		// whitespace is of 1, for text of 3 words, the number of
		// whitespace is of 2, for text of 4 words, the number of
		// whitespace is of 3, etc ...
		// the relation between words in a text and whitespace
		// character is:
		// 		y = x - 1
		// where:
		// y = number of whitespace characters in the text
		// x = number of words in the text
		if (countOfWhitespace >= (x - 1))
		{
			return true;
		}
	}

	return false;
}

bool Pocon::WriterFile::HaveFourWords(std::string_view _word)
{
	return HaveXWords(4, _word);
}


bool Pocon::WriterFile::HaveThreeWords(std::string_view _word)
{
	return HaveXWords(3, _word);
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

std::string Pocon::WriterFile::GetNameShortForAElementOfFourWords(std::string_view _basedIn)
{
	std::vector <std::string> var = ExtractTheFourWordsMoreLengthOf(_basedIn);

	for (std::string& s : var)
	{
		CapitalizeTheFirstLetterOf(s);
	}

	return std::string(var[0] + var[1] + var[2] + var[3]);
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

std::vector <std::string> Pocon::WriterFile::ExtractTheXWordsMoreLengthOf(std::string_view _word, const unsigned int x)
{
	std::vector <std::string> wordsInString = ExtractAllWordsOfAString(_word);

	while (wordsInString.size() > x)
	{
		DeleteTheWordMoreShortOf(wordsInString);
	}

	return wordsInString;
}

std::vector <std::string> Pocon::WriterFile::ExtractTheFourWordsMoreLengthOf(std::string_view _word)
{
	return ExtractTheXWordsMoreLengthOf(_word, 4);
}

std::vector <std::string> Pocon::WriterFile::ExtractTheThreeWordsMoreLengthOf(std::string_view _word)
{
	return ExtractTheXWordsMoreLengthOf(_word, 3);
}

std::vector <std::string> Pocon::WriterFile::ExtractTheTwoWordsMoreLengthOf(std::string_view _word)
{
	return ExtractTheXWordsMoreLengthOf(_word, 2);
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

void Pocon::WriterFile::FormatStringToCapitalize(std::string& _string)
{
	for (unsigned long i = 1; i < _string.size(); i++)
	{
		_string[i] = std::tolower(_string[i]);
	}
}
