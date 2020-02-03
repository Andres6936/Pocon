#include "Xml.hpp"

using namespace Pocon;

void Xml::ConvertBufferToXml(const ReaderFile& reader)
{
	// Get the buffer of file po
	std::string buffer = reader.GetBuffer();

	// Word, with format:
	// first -> origin
	// second -> translate
	WordTranslate word;

	// Dictionary of words translate.
	std::vector <WordTranslate> dictionary;

	int positionStartOrigin = 0;
	int positionEndOrigin = 0;

	int positionStartTranslate = 0;
	int positionEndTranslate = 0;

	while (true)
	{
		positionStartOrigin = buffer.find("msgid", positionStartOrigin);
		positionEndOrigin = buffer.find('\n', positionStartOrigin);

		// End of file
		if (positionStartOrigin == std::string::npos)
		{
			break;
		}

		std::string origin = buffer.substr(positionStartOrigin, positionEndOrigin - positionStartOrigin);

		positionStartTranslate = buffer.find("msgstr", positionStartTranslate);
		positionEndTranslate = buffer.find("msgid", positionStartTranslate);

		std::string translate = buffer.substr(positionStartTranslate, positionEndTranslate - positionStartTranslate);

		word.first = origin;
		word.second = translate;

		dictionary.push_back(word);

		// Advance to next word

		positionStartOrigin += 1;
		positionStartTranslate += 1;
	}

	// In this point, the buffer is unnecessary
	buffer.clear();

	ClearDictionaryOfTagsUnused(dictionary);

	// The dictionary content the properties of file. See files .po
	std::vector <PropertyFile> properties = ExtractPropertiesOfFile(dictionary);
	// The dictionary content the license of file. See files .po
	std::string license = ExtractLicenseOfFile(dictionary);
	// The dictionary content the translator credits of file. See files .po
	std::vector <std::string> credits = ExtractTranslatorCreditsOfFile(dictionary);
}

void Xml::ClearDictionaryOfTagsUnused(std::vector <WordTranslate>& _dictionary)
{
	for (WordTranslate& word : _dictionary)
	{
		ClearWordOfTagsUnused(word);
	}
}

void Xml::ClearWordOfTagsUnused(WordTranslate& _word)
{
	std::string origin = _word.first;
	std::string translate = _word.second;

	// Delete the string {msgid }
	RemoveStringInString(origin, "msgid ");
	// Delete the string {msgstr }
	RemoveStringInString(translate, "msgstr ");

	// Delete all the characters {"}
	RemoveCharInString(origin, '\"');
	RemoveCharInString(translate, '\"');
	// Delete all the characters {\n}
	RemoveCharInString(translate, '\n');

	int position = translate.find("#:");

	if (position != std::string::npos)
	{
		// Delete the coincidence to end of string
		translate.erase(position);
	}

	// Special Case, the string can be empty
	if (origin.empty())
	{
		// Replaced for {None}
		_word.first = "None";
	}
	else
	{
		_word.first = origin;
	}

	_word.second = translate;
}

void Xml::RemoveCharInString(std::string& _string, char _char)
{
	int position = _string.find(_char);

	while (position != std::string::npos)
	{
		// Remove only a character
		_string.erase(position, 1);
		position = _string.find(_char);
	}
}

void Xml::RemoveStringInString(std::string& _string, const std::string& _coincidence)
{
	int position = _string.find(_coincidence);

	if (position == std::string::npos)
	{
		return;
	}
	else
	{
		_string.erase(position, _coincidence.size());
	}
}

std::vector <PropertyFile> Xml::ExtractPropertiesOfFile(std::vector <WordTranslate>& _dictionary)
{
	// Generally the first translate of dictionary content the properties of file.
	// This properties are saved in value.
	// Ignore the value of key, its None.
	std::string propertiesInRaw = _dictionary.at(0).second;
	// Delete the properties of dictionary
	_dictionary.erase(_dictionary.begin());

	// Property of file.
	PropertyFile property;
	// Here, saved the properties of file that will be returned.
	std::vector <PropertyFile> properties;

	// Mark the point where we find the character {:}
	int positionStart = 0;
	// Mark the point where we find the sequence {\n}
	int positionEnd = 0;

	positionStart = propertiesInRaw.find(':');

	// If the file .po not content the properties in first translate
	// throw an exception.
	if (positionStart == std::string::npos)
	{
		throw "InvalidFormatFilePOException";
	}

	do
	{
		// Objective Line: Extract the name of property.
		// - positionEnd mark the start of name property.
		// - Note that for the first iterator, the value of positionEnd is 0.
		// - The rest, {start - end} mark the length of name property.
		property.first = propertiesInRaw.substr(positionEnd, positionStart - positionEnd);

		// Objective Line: Find the sequence of characters {\n} that mark the end of property
		// - Note that for the first iterator, the value of positionStart is greater than 0.
		positionEnd = propertiesInRaw.find("\\n", positionStart);

		// Objective Line: Extract the value of property
		// - {positionStart + 1} for avoid added the character {:} to string
		// - Note that in this point, positionEnd is greater than positionStart
		// - {end - start} mark the length of value of property
		// - {length - 1} for avoid added the character {\} to string
		property.second = propertiesInRaw.substr(positionStart + 1, positionEnd - positionStart - 1);

		// Save the property
		properties.push_back(property);

		// Objective Line: Advance to next property
		// - positionEnd += 2 for jump the characters {\n}
		// - positionStart start to find the character {:} then of any character {\n}
		positionEnd += 2;
		positionStart = propertiesInRaw.find(':', positionEnd);
	} while (positionStart != std::string::npos);

	return properties;
}

std::string Xml::ExtractLicenseOfFile(std::vector <WordTranslate>& _dictionary)
{
	// The license in the file .po is divided in three parts
	// It mean that the dictionary content three word translate with the license

	WordTranslate part1 = _dictionary.at(0);
	WordTranslate part2 = _dictionary.at(1);
	WordTranslate part3 = _dictionary.at(2);

	// Remove the license of dictionary
	_dictionary.erase(_dictionary.begin(), _dictionary.begin() + 3);

	return std::string(part1.second + part2.second + part3.second);
}

std::vector <std::string> Xml::ExtractTranslatorCreditsOfFile(std::vector <WordTranslate>& _dictionary)
{
	std::vector <std::string> translatorCredits;

	// Get the string with the translators.
	std::string translators = _dictionary.at(0).second;
	// Delete the translators of dictionary
	_dictionary.erase(_dictionary.begin());

	// Start line, saved the value of variable {position},
	// because it [the variable position] cannot marked
	// the start of line and the end of line at same time.
	int startLine = 0;

	// Position have the property of mark the start and end of an line.
	// Because to mark the character {\n} is marked the end of line
	// and too is marked the start of new line.
	int position = translators.find("\\n");

	// An special case, is that only exits an translator,
	// the format of files .po allow that if only exist an line,
	// it no need finalize with the character {\n}, is for this
	// need make this verification and return only the string to end.
	if (position == std::string::npos)
	{
		// Added the string without modifications.
		translatorCredits.push_back(translators);
		// Exit of function.
		return translatorCredits;
	}

	while (true)
	{
		// startLine mark the start of string
		// {position - startLine} mark the length of string
		translatorCredits.push_back(translators.substr(startLine, position - startLine));
		// Advance to next line
		position += 1;
		// Remember the end of line and the start of the next line.
		// Is need add 1, for avoid add the character {n}
		startLine = position + 1;
		position = translators.find("\\n", position);

		// The ultimate translator not finalize with the character {\n}
		if (position == std::string::npos)
		{
			// As not exits an character {\n}, the substring got to end.
			translatorCredits.push_back(translators.substr(startLine));
			// Exit loop.
			break;
		}
	}

	return translatorCredits;
}
