#include "Xml.hpp"
#include "Writable.hpp"
#include "Exception.hpp"

using namespace Pocon;

void Xml::ConvertBufferToXml(std::string_view filename)
{
	try
	{
		// Read the filename
		ReadFile(filename);
	}
	catch (Exception& exception)
	{
		exception.ShowError();
	}

	// Get the buffer of file po
	std::string buffer = GetBuffer();
	// Remove comments of buffer
	RemoveCommentsOfBuffer(buffer);

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
		// Each word translate of file .po have the format of:
		// - msgid: for the origin
		// - msgstr: for the translate

		// We want take all the string that begin in {msgid } and finalize in {msgstr}.
		// This string will be the origin.
		positionStartOrigin = buffer.find("msgid", positionStartOrigin);
		positionEndOrigin = buffer.find("msgstr", positionStartOrigin);

		// End of file
		if (positionStartOrigin == std::string::npos)
		{
			// Exit of loop.
			break;
		}

		// Get the origin string
		// - {end - start} mark the length of string origin
		// - {length - 2} for avoid add the sequence {\n} to string
		std::string origin = buffer.substr(positionStartOrigin, positionEndOrigin - positionStartOrigin - 2);

		// We want take all the string that begin in {msgstr } and finalize in {msgid}.
		// This string will be the translate.
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
	FormatLicenseAddNewLine(license);

	// The dictionary content the translator credits of file. See files .po
	std::vector <std::string> credits = ExtractTranslatorCreditsOfFile(dictionary);

	Writable writer = Writable();
	writer.SetDictionary(dictionary);
	writer.SetPropertiesFile(properties);
	writer.SetLicenseFile(license);
	writer.SetCreditsFile(credits);

	// Clear for free memory.
	// Note: Writable save an copy of each of items.
	dictionary.clear();
	properties.clear();
	license.clear();
	credits.clear();

	writer.CreateFileStruct();
	writer.CreateNameOfElements();
	writer.CreateElementsAndTranslates();
	writer.SaveFileInFormatXml();
}

void Xml::ClearDictionaryOfTagsUnused(std::vector <WordTranslate>& _dictionary)
{
	for (WordTranslate& word : _dictionary)
	{
		ClearWordOfTagsUnused(word);
		ClearWordOfUnderscore(word);

		// Is important that is line will be executed
		// after that the ClearStringOfColon method.
		ClearStringOfFormatSequences(word.first);
		// Is important that is line will be executed
		// before that the ClearStringOfFormatSequences method.
		ClearStringOfColon(word.first);
		ClearStringOfComma(word.first);
		ClearStringOfDoubleLine(word.first);
		ClearStringOfApostrophe(word.first);
		ClearStringOfNumberSign(word.first);
		ClearStringOfParenthesis(word.first);
		ClearStringOfQuestionMark(word.first);
		ClearStringOfDecimalPoint(word.first);
		ClearStringOfVerticalLine(word.first);
		ClearStringOfWordsSeparatedWithHyphen(word.first);
	}
}

void Xml::ClearWordOfTagsUnused(WordTranslate& _word)
{
	std::string origin = _word.first;
	std::string translate = _word.second;

	// Delete all the characters {"}
	RemoveCharInString(origin, '\"');
	RemoveCharInString(translate, '\"');
	// Delete all the characters {\n}
	RemoveCharInString(origin, '\n');
	RemoveCharInString(translate, '\n');

	// Delete the string {msgid }
	RemoveStringInString(origin, "msgid ");
	// Delete the string {msgstr }
	RemoveStringInString(translate, "msgstr ");

	// Delete all the string {\\n}
	RemoveStringInString(origin, "\\n");

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
	long position = _string.find(_char);

	while (position != std::string::npos)
	{
		// Remove only a character
		_string.erase(position, 1);
		position = _string.find(_char);
	}
}

void Xml::RemoveStringInString(std::string& _string, const std::string& _coincidence)
{
	long position = _string.find(_coincidence);

	while (position != std::string::npos)
	{
		_string.erase(position, _coincidence.size());
		position = _string.find(_coincidence);
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

void Xml::ClearWordOfUnderscore(WordTranslate& _word)
{
	RemoveCharInString(_word.first, '_');
	RemoveCharInString(_word.second, '_');
}

void Xml::ClearStringOfDecimalPoint(std::string& _string)
{
	RemoveCharInString(_string, '.');
}

void Xml::ClearStringOfApostrophe(std::string& _string)
{
	RemoveCharInString(_string, '\'');
}

void Xml::ClearStringOfDoubleLine(std::string& _string)
{
	RemoveStringInString(_string, "--");
}

void Xml::ClearStringOfParenthesis(std::string& _string)
{
	RemoveCharInString(_string, '(');
	RemoveCharInString(_string, ')');
}

void Xml::ClearStringOfColon(std::string& _string)
{
	RemoveCharInString(_string, ':');
}

void Xml::ClearStringOfFormatSequences(std::string& _string)
{
	long positionPercentSign = _string.find('%');
	long positionColon = _string.find(':');

	while (positionPercentSign != std::string::npos)
	{
		if (positionColon == std::string::npos)
		{
			long positionWhiteSpace = _string.find(' ', positionPercentSign);

			// Special case, can that not exist whitespace,
			// thus removed only the character {%}
			if (positionWhiteSpace == std::string::npos)
			{
				RemoveCharInString(_string, '%');
				// Exit loop.
				break;
			}

			// Deleted character to find a whitespace { }
			_string.erase(positionPercentSign, positionWhiteSpace - positionPercentSign);
			// Exit loop.
			break;
		}

		// Deleted characters to colon
		_string.erase(positionPercentSign, positionColon - positionPercentSign);

		// Advance to next format sequence
		positionPercentSign = _string.find('%');
		positionColon = _string.find(':');
	}
}

void Xml::ClearStringOfQuestionMark(std::string& _string)
{
	RemoveCharInString(_string, '?');
}

void Xml::ClearStringOfNumberSign(std::string& _string)
{
	RemoveCharInString(_string, '#');
}

void Xml::RemoveCommentsOfBuffer(std::string& _buffer)
{
	// Generally, the comments begin before of a new
	// line {\n}, follow of an character of number
	// sign {#} and finalize with an character of
	// new line {\n}

	long positionStartComment = _buffer.find("\n#");
	long positionEndComment = 0;

	while (positionStartComment != std::string::npos)
	{
		// The comments and the document always finalize with the character {\n}
		// Thus, the condition of find an character {\n} always is true.
		// - Is needed add 2 to positionStartComment for avoid that the
		// 		character {\n} that mark the begin of the comment will be marked
		// 		like the character that finalize the comment.
		positionEndComment = _buffer.find('\n', positionStartComment += 2);

		// Reset the value for defect of positionStartComment
		positionStartComment -= 2;

		// We remove only the character {#} that mark the begin of the comment,
		// the character {\n} that is back of {#} not is removed.
		// - Is needed add 1 to positionStartComment to avoid delete the character {\n}
		// - {EndComment - StartComment} mark the length of line, include the character {\n}
		_buffer.erase(positionStartComment + 1, positionEndComment - positionStartComment);

		// Advance to next comment
		positionStartComment = _buffer.find("\n#");
	}

	// A special case that can happen, is that the file .po begin with a
	// comment, thus the first character of document will be number
	// sign {#}, this comment not will be removed for the code above,
	// and needed of an code new that manage this case.
	RemoveCommentsOfBufferInFirstLine(_buffer);
}

void Xml::RemoveCommentsOfBufferInFirstLine(std::string& _buffer)
{
	// If the first character of buffer is an comment {#}, remove
	// the comment to find an character of new line {\n}
	// - The character of new line too will be removed.
	if (_buffer.at(0) == '#')
	{
		// Remember that an comment and the any file always finalize
		// with an character of new line {\n}
		// - Not is possible get an std::string::npos as return of find method
		long positionNewLine = _buffer.find('\n');

		// Deleted all line completely, include the character of new line {\n}
		_buffer.erase(0, positionNewLine + 1);
	}
}

void Xml::ClearStringOfVerticalLine(std::string& _string)
{
	RemoveCharInString(_string, '|');
}

void Xml::ClearStringOfComma(std::string& _string)
{
	RemoveCharInString(_string, ',');
}

void Xml::ClearStringOfWordsSeparatedWithHyphen(std::string& _string)
{
	int positionHyphen = _string.find('-');

	while (positionHyphen != std::string::npos)
	{
		// We may verify that the next character
		// of {-} too be an alphabetic character.
		// but in my opinion, not is needed, only
		// needed verify if exits an alphabetic after
		// of {-}.
		// Other problem that can happen is if the
		// character {-} is found to begin of string
		// {position = 0}, for avoid an out_range
		// exception, we must verify that the character
		// {-} is found in a position more greater than 0.
		if (positionHyphen > 0 && std::isalpha(_string[positionHyphen - 1]))
		{
			// Replaced the character for an whitespace
			_string.replace(positionHyphen, 1, " ");
		}

		// Advance to next character {-}
		positionHyphen = _string.find('-', ++positionHyphen);
	}
}

void AddNewLineInReplaceOfString(std::string_view toReplaced, std::string& _string)
{
	int positionString = _string.find(toReplaced);

	while (positionString != std::string::npos)
	{
		_string.replace(positionString, toReplaced.size(), "\n");

		positionString = _string.find(toReplaced);
	}
}

std::vector <std::string> DivideStringIndicateForTheCharacter(char _char, std::string_view _string)
{
	std::vector <std::string> vectorString;

	int positionChar = _string.find(_char);
	int rememberPositionChar = 0;

	while (positionChar != std::string::npos)
	{
		std::string licensePart = (std::string)_string.substr(rememberPositionChar,
				positionChar - rememberPositionChar + 1);
		vectorString.push_back(licensePart);

		rememberPositionChar = ++positionChar;
		positionChar = _string.find(_char, positionChar);
	}

	return vectorString;
}

void ConcatenateStringVerySmallInOne(std::vector <std::string>& _vector)
{
	constexpr int SMALL_STRING = 15;

	for (int i = 0; i < _vector.size(); ++i)
	{
		if (_vector[i].size() < SMALL_STRING)
		{
			std::string smallString = _vector[i];
			_vector.erase(_vector.begin() + i);

			if (i > 0)
			{
				_vector[i - 1] = _vector[i - 1] + smallString;
			}
		}
	}
}

void AddNewLineForBreakLineOfGreatString(std::string& _string)
{
	constexpr short LINE_BREAKING = 90;

	int positionWhitespace = _string.find(' ', LINE_BREAKING);

	unsigned int numberOfIteration = 1;

	while (positionWhitespace != std::string::npos)
	{
		_string.replace(positionWhitespace, 1, "\n");

		numberOfIteration++;

		positionWhitespace = _string.find(' ', LINE_BREAKING * numberOfIteration);
	}
}

void Xml::FormatLicenseAddNewLine(std::string& _license)
{
	std::vector <std::string> licenseDivided = DivideStringIndicateForTheCharacter('.', _license);
	ConcatenateStringVerySmallInOne(licenseDivided);

	_license.clear();

	for (std::string& s : licenseDivided)
	{
		AddNewLineInReplaceOfString("\\n", s);
		AddNewLineForBreakLineOfGreatString(s);

		// Added a new line to end of each string
		s.push_back('\n');
		// Updated we license
		_license.append(s);
	}
}