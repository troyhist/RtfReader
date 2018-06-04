
#include "../RtfPars/RtfParser.hpp"				// RtfParser
#include "../RtfPars/RtfParser$Kernel.hpp"		// prototypes self-control

#include "../RtfPars/RtfParser$Params.hpp"		// RtfParser$Params
#include "../RtfPars/parsererr_t.h"

/* ======================================================================= */
// fills token map with data
RtfParser::Kernel::TokenTypes	RtfParser::Kernel::getTokenTypes()	{
	// 2008.01.31

	TokenTypes	res;

	res.insert(TokenTypes::value_type("\\'", RTFRD_KW_HEX));
	res.insert(TokenTypes::value_type("\\*", RTFRD_KW_SKIP));
	res.insert(TokenTypes::value_type("{", RTFRD_KW_BRKL));
	res.insert(TokenTypes::value_type("}", RTFRD_KW_BRKR));
	res.insert(TokenTypes::value_type("\\", RTFRD_KW_KW));
	res.insert(TokenTypes::value_type("\r", RTFRD_KW_NOISE));
	res.insert(TokenTypes::value_type("\n", RTFRD_KW_NOISE));

	return res;
	}
/* ======================================================================= */
RtfParser::Kernel::TokenTypes RtfParser::Kernel::ms_tokenTypes	= RtfParser::Kernel::getTokenTypes();
/* ======================================================================= */
// rtf parser kernel
RtfParser::Kernel::Kernel(
		RtfParser	&parser):
	m_parser(parser)	{
	}
/* ======================================================================= */
// returns a type of a symbol
RtfParser::Kernel::symboltype_t RtfParser::Kernel::getSymbType(const std::string &str)	{
	// 2008.01.31

	TokenTypes::const_iterator it	= ms_tokenTypes.find(str);
	if(ms_tokenTypes.end() != it)
		return((*it).second);

	return(RTFRD_KW_NONE);
	}
/* ======================================================================= */
// returns a type of a symbol
RtfParser::Kernel::symboltype_t RtfParser::Kernel::getSymbType()	{
	// 2005.08.18
	// 2008.01.31

	int					currOffs	= m_parser.getOffs();
	const std::string	&buf		= m_parser.getBuf();

	{
		std::string token	= buf.substr(currOffs, 2);
		symboltype_t res	= getSymbType(token);

		if(RTFRD_KW_NONE != res)
		{
			m_parser.addOffset(2);
			return(res);
		}
	}

	{
		std::string token	= buf.substr(currOffs, 1);
		symboltype_t res	= getSymbType(token);

		if(RTFRD_KW_NONE != res)
		{
			m_parser.addOffset(1);
			return(res);
		}
	}

	return(RTFRD_KW_NONE);
	}
/* ======================================================================= */
// defines block start position
void RtfParser::Kernel::setBlkType(
		const RtfParser::blocktype_t	blockType,
		const int						nOffset)	{
	// 2005.08.19
	
	if (blockType == m_parser.m_blockType)
		return;

	m_parser.setBlkStop(nOffset);
	m_parser.printCurrBlock();

	m_parser.setBlkStart(nOffset);
	m_parser.m_blockType	=	blockType;

	}
/* ======================================================================= */
// defines end of parsing
void RtfParser::Kernel::setBlkEnd()	{
	// 2005.08.19
	m_parser.setBlkStop(m_parser.m_size);

	m_parser.printCurrBlock();
	}
/* ======================================================================= */
//
// %%Function: RtfParser::Kernel::Kernel
//
// Step 1:
// Isolate RTF keywords and send them to RtfParser::Kernel::ParseEsc;
// Push and pop state at the start and end of RTF groups;
// Send text to RtfParser::Kernel::ParseChar for further processing.
//

// rtf parser kernel
int RtfParser::Kernel::parse()	{
	// 2005.08.18

	while (m_parser.getOffs() < m_parser.m_size)
		{
		int				nOffset		= m_parser.getOffs();
		symboltype_t	symbolType	= getSymbType();

		switch(symbolType)
			{
			// -----------------------------------------------------------
			// hex number
			case RTFRD_KW_HEX:
				setBlkType(RTF_BLKTYPE_TXT, nOffset);
				m_parser.addOffset(2);
				break;
			// -----------------------------------------------------------
			// block to skip
			case RTFRD_KW_SKIP:
				setBlkType(RTF_BLKTYPE_CTRL, nOffset);
				m_parser.setSkipDestIfUnk(true);
				break;
			// -----------------------------------------------------------
			// left figure bracket
			case RTFRD_KW_BRKL:
				{
				bool bSkip		= m_parser.isSkipping();

				setBlkType(RTF_BLKTYPE_CTRL, nOffset);

				m_parser.m_stackSize++;

				parse();

				m_parser.setSkip(bSkip);
				}
				break;
			// -----------------------------------------------------------
			// right figure bracket
			case RTFRD_KW_BRKR:
				{
				setBlkType(RTF_BLKTYPE_CTRL, nOffset);
				m_parser.m_stackSize--;
				return(ecOK);
				}
				break;
			// -----------------------------------------------------------
			// keyword
			case RTFRD_KW_KW:
				{
				setBlkType(RTF_BLKTYPE_CTRL, nOffset);

				RtfParser::Params par(m_parser);
				par.process();
				}
				break;
			// -----------------------------------------------------------
			// noise characters
			case RTFRD_KW_NOISE:
				break;
			// -----------------------------------------------------------
			// not a keyword, process as a text symbol
			case RTFRD_KW_NONE:

				setBlkType(RTF_BLKTYPE_TXT, nOffset);
				m_parser.incOffset();

				break;
			// -----------------------------------------------------------
			default:
				printf("ERROR: unknown type (symbolType = %d)\n", symbolType);
				break;
			}

		if (m_parser.m_stackSize < 0)
			return(ecStackUnderflow);

		}	// while
	// -------------------------------------------------------------------
	setBlkEnd();
	// -------------------------------------------------------------------
	return(ecOK);
	}
/* ======================================================================= */
