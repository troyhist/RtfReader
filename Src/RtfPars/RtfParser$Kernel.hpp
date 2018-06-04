
#ifndef _RtfParser_Kernel_HPP_
#define _RtfParser_Kernel_HPP_

#include <map>
#include <string>

class RtfParser;

class RtfParser::Kernel
{

	enum symboltype_t
	{
		RTFRD_KW_NONE	= 0,
		RTFRD_KW_BRKL,
		RTFRD_KW_BRKR,
		RTFRD_KW_HEX,
		RTFRD_KW_SKIP,
		RTFRD_KW_KW,
		RTFRD_KW_NOISE,
	};

	typedef std::map<std::string, symboltype_t>		TokenTypes;

	// Construction:
	public:
	
	// rtf parser kernel
	RtfParser::Kernel(
			RtfParser	&parser);

	private:
		RtfParser::Kernel(const RtfParser::Kernel&);
		RtfParser::Kernel& operator=(const RtfParser::Kernel&);

	// Properties:
	public:

	// Operations:
	public:

		// rtf parser kernel
		int parse();

	// Implementation:
	private:
		static symboltype_t getSymbType(const std::string &str);

		symboltype_t getSymbType();

		// defines block start position
		void setBlkType(
				const RtfParser::blocktype_t	nBlkType,
				const int						nOffset);

		// defines end of parsing
		void setBlkEnd();

		static TokenTypes	getTokenTypes();

		RtfParser			&m_parser;
		static TokenTypes	ms_tokenTypes;

};

#endif	// _RtfParser_Kernel_HPP_
