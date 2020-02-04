#ifndef TICPP_TIXMLHANDLE_HPP
#define TICPP_TIXMLHANDLE_HPP

#include "Ana.hpp"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

namespace Ana
{


/**
	A TiXmlHandle is a class that wraps a node pointer with null checks; this is
	an incredibly useful thing. Note that TiXmlHandle is not part of the TinyXml
	DOM structure. It is a separate utility class.

	Take an example:
	@verbatim
	<Document>
		<Element attributeA = "valueA">
			<Child attributeB = "value1" />
			<Child attributeB = "value2" />
		</Element>
	<Document>
	@endverbatim

	Assuming you want the value of "attributeB" in the 2nd "Child" element, it's very
	easy to write a *lot* of code that looks like:

	@verbatim
	Element* root = document.FirstChildElement( "Document" );
	if ( root )
	{
		Element* element = root->FirstChildElement( "Element" );
		if ( element )
		{
			Element* child = element->FirstChildElement( "Child" );
			if ( child )
			{
				Element* child2 = child->NextSiblingElement( "Child" );
				if ( child2 )
				{
					// Finally do something useful.
	@endverbatim

	And that doesn't even cover "else" cases. TiXmlHandle addresses the verbosity
	of such code. A TiXmlHandle checks for null	pointers so it is perfectly safe
	and correct to use:

	@verbatim
	TiXmlHandle docHandle( &document );
	Element* child2 = docHandle.FirstChild( "Document" ).FirstChild( "Element" ).Child( "Child", 1 ).ToElement();
	if ( child2 )
	{
		// do something useful
	@endverbatim

	Which is MUCH more concise and useful.

	It is also safe to copy handles - internally they are nothing more than node pointers.
	@verbatim
	TiXmlHandle handleCopy = handle;
	@endverbatim

	What they should not be used for is iteration:

	@verbatim
	int i=0;
	while ( true )
	{
		Element* child = docHandle.FirstChild( "Document" ).FirstChild( "Element" ).Child( "Child", i ).ToElement();
		if ( !child )
			break;
		// do something
		++i;
	}
	@endverbatim

	It seems reasonable, but it is in fact two embedded while loops. The Child method is
	a linear walk to find the element, so this code would iterate much more than it needs
	to. Instead, prefer:

	@verbatim
	Element* child = docHandle.FirstChild( "Document" ).FirstChild( "Element" ).FirstChild( "Child" ).ToElement();

	for( child; child; child=child->NextSiblingElement() )
	{
		// do something
	}
	@endverbatim
*/
	class TiXmlHandle
	{
	public:
		/// Create a handle from any node (at any depth of the tree.) This can be a null pointer.
		explicit TiXmlHandle(TiXmlNode* _node)
		{
			this->node = _node;
		}

		/// Copy constructor
		TiXmlHandle(const TiXmlHandle& ref)
		{
			this->node = ref.node;
		}

		TiXmlHandle operator=(const TiXmlHandle& ref)
		{
			this->node = ref.node;
			return *this;
		}

		/// Return a handle to the first child node.
		TiXmlHandle FirstChild() const;

		/// Return a handle to the first child node with the given name.
		TiXmlHandle FirstChild(const char* value) const;

		/// Return a handle to the first child element.
		TiXmlHandle FirstChildElement() const;

		/// Return a handle to the first child element with the given name.
		TiXmlHandle FirstChildElement(const char* value) const;

		/** Return a handle to the "index" child with the given name.
			The first child is 0, the second 1, etc.
		*/
		TiXmlHandle Child(const char* value, int index) const;

		/** Return a handle to the "index" child.
			The first child is 0, the second 1, etc.
		*/
		TiXmlHandle Child(int index) const;

		/** Return a handle to the "index" child element with the given name.
			The first child element is 0, the second 1, etc. Note that only TiXmlElements
			are indexed: other types are not counted.
		*/
		TiXmlHandle ChildElement(const char* value, int index) const;

		/** Return a handle to the "index" child element.
			The first child element is 0, the second 1, etc. Note that only TiXmlElements
			are indexed: other types are not counted.
		*/
		TiXmlHandle ChildElement(int index) const;

		TiXmlHandle FirstChild(const std::string& _value) const
		{
			return FirstChild(_value.c_str());
		}

		TiXmlHandle FirstChildElement(const std::string& _value) const
		{
			return FirstChildElement(_value.c_str());
		}

		TiXmlHandle Child(const std::string& _value, int index) const
		{
			return Child(_value.c_str(), index);
		}

		TiXmlHandle ChildElement(const std::string& _value, int index) const
		{
			return ChildElement(_value.c_str(), index);
		}

		/** Return the handle as a TiXmlNode. This may return null.
		*/
		TiXmlNode* ToNode() const
		{
			return node;
		}

		/** Return the handle as a Element. This may return null.
		*/
		Element* ToElement() const
		{
			return ((node && node->ToElement()) ? node->ToElement() : nullptr);
		}

		/**	Return the handle as a Text. This may return null.
		*/
		Text* ToText() const
		{
			return ((node && node->ToText()) ? node->ToText() : nullptr);
		}

		/** Return the handle as a Unknown. This may return null.
		*/
		Unknown* ToUnknown() const
		{
			return ((node && node->ToUnknown()) ? node->ToUnknown() : nullptr);
		}

	private:

		TiXmlNode* node;
	};

}

#endif //TICPP_TIXMLHANDLE_HPP