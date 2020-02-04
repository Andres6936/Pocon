#ifndef TICPP_TIXMLVISITOR_HPP
#define TICPP_TIXMLVISITOR_HPP

#include "Ana.hpp"

namespace Ana
{


/**
	If you call the Accept() method, it requires being passed a TiXmlVisitor
	class to handle callbacks. For nodes that contain other nodes (Document, Element)
	you will get called with a VisitEnter/VisitExit pair. Nodes that are always leaves
	are simple called with Visit().

	If you return 'true' from a Visit method, recursive parsing will continue. If you return
	false, <b>no children of this node or its sibilings</b> will be Visited.

	All flavors of Visit methods have a default implementation that returns 'true' (continue
	visiting). You need to only override methods that are interesting to you.

	Generally Accept() is called on the Document, although all nodes suppert Visiting.

	You should never change the document from a callback.

	@sa TiXmlNode::Accept()
*/
	class TiXmlVisitor
	{

	public:

		virtual ~TiXmlVisitor() = default;

		/// Visit a document.
		virtual bool VisitEnter(const Document& /*doc*/ )
		{
			return true;
		}

		/// Visit a document.
		virtual bool VisitExit(const Document& /*doc*/ )
		{
			return true;
		}

		/// Visit an element.
		virtual bool VisitEnter(const Element& /*element*/, const Attribute* /*firstAttribute*/ )
		{
			return true;
		}

		/// Visit an element.
		virtual bool VisitExit(const Element& /*element*/ )
		{
			return true;
		}

		/// Visit a declaration
		virtual bool Visit(const Declaration& /*declaration*/ )
		{
			return true;
		}

		/// Visit a stylesheet reference
		virtual bool Visit(const StylesheetReference& /*stylesheet*/ )
		{
			return true;
		}

		/// Visit a text node
		virtual bool Visit(const Text& /*text*/ )
		{
			return true;
		}

		/// Visit a comment node
		virtual bool Visit(const Comment& /*comment*/ )
		{
			return true;
		}

		/// Visit an unknow node
		virtual bool Visit(const Unknown& /*unknown*/ )
		{
			return true;
		}
	};

}

#endif //TICPP_TIXMLVISITOR_HPP
