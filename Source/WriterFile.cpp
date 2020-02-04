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

}
