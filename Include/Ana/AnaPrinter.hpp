#ifndef TICPP_TIXMLPRINTER_HPP
#define TICPP_TIXMLPRINTER_HPP

#include "Ana.hpp"

#include "AnaVisitor.hpp"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

namespace Ana
{


/** Print to memory functionality. The TiXmlPrinter is useful when you need to:

	-# Print to memory (especially in non-STL mode)
	-# Control formatting (line endings, etc.)

	When constructed, the TiXmlPrinter is in its default "pretty printing" mode.
	Before calling Accept() you can call methods to control the printing
	of the XML document. After TiXmlNode::Accept() is called, the printed document can
	be accessed via the CStr(), Str(), and Size() methods.

	TiXmlPrinter uses the Visitor API.
	@verbatim
	TiXmlPrinter printer;
	printer.SetIndent( "\t" );

	doc.Accept( &printer );
	fprintf( stdout, "%s", printer.CStr() );
	@endverbatim
*/
	class TiXmlPrinter : public TiXmlVisitor
	{
	public:
		TiXmlPrinter() : depth(0), simpleTextPrint(false),
						 buffer(), indent("    "), lineBreak("\n")
		{
		}

		bool VisitEnter(const Document& doc) override;

		bool VisitExit(const Document& doc) override;

		bool VisitEnter(const Element& element, const Attribute* firstAttribute) override;

		bool VisitExit(const Element& element) override;

		bool Visit(const Declaration& declaration) override;

		bool Visit(const Text& text) override;

		bool Visit(const Comment& comment) override;

		bool Visit(const Unknown& unknown) override;

		bool Visit(const StylesheetReference& stylesheet) override;

		/** Set the indent characters for printing. By default 4 spaces
			but tab (\t) is also useful, or null/empty string for no indentation.
		*/
		void SetIndent(const char* _indent)
		{
			indent = _indent ? _indent : "";
		}

		/// Query the indention string.
		const char* Indent()
		{
			return indent.c_str();
		}

		/** Set the line breaking string. By default set to newline (\n).
			Some operating systems prefer other characters, or can be
			set to the null/empty string for no indenation.
		*/
		void SetLineBreak(const char* _lineBreak)
		{
			lineBreak = _lineBreak ? _lineBreak : "";
		}

		/// Query the current line breaking string.
		const char* LineBreak()
		{
			return lineBreak.c_str();
		}

		/** Switch over to "stream printing" which is the most dense formatting without
			linebreaks. Common when the XML is needed for network transmission.
		*/
		void SetStreamPrinting()
		{
			indent = "";
			lineBreak = "";
		}

		/// Return the result.
		const char* CStr()
		{
			return buffer.c_str();
		}

		/// Return the length of the result string.
		size_t Size()
		{
			return buffer.size();
		}

		/// Return the result.
		const std::string& Str()
		{
			return buffer;
		}

	private:
		void DoIndent()
		{
			for (int i = 0; i < depth; ++i)
			{
				buffer += indent;
			}
		}

		void DoLineBreak()
		{
			buffer += lineBreak;
		}

		int depth;
		bool simpleTextPrint;
		std::string buffer;
		std::string indent;
		std::string lineBreak;
	};

}

#endif //TICPP_TIXMLPRINTER_HPP
