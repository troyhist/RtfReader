
#include "../RtfPars/RtfParser.hpp"				// RtfParser
#include "../RtfPars/RtfParser$Params.hpp"		// prototypes self-control

#include "../RtfPars/RtfParser$Keywords.hpp"	// RtfParser$Keywords

#include <tcilib/src/syswrap/convert/CConvertStr.hpp>	// CConvertStr
#include <stdio.h>				// EOF
#include <ctype.h>				// isalpha, isdigit

//#include "../RtfPars/RtfPars_f_i.h"		// RtfParser::incOffset, etc.
//#include "../RtfPars/RtfPars_f_kwd.h"		// RtfParser::process
#include "../RtfPars/parsererr_t.h"		// errorcodes: ec...

/* ======================================================================= */
// rtf parser kernel
RtfParser::Params::Params(
		RtfParser	&parser):
	m_parser(parser)	{
	}
/* ======================================================================= */
// extracts parameter, keyword
int RtfParser::Params::extractKeyword(
		char			*szKeyword)	{
	// 2005.08.17

	char *pch;
	for (pch = szKeyword; isalpha(m_parser.getSymb()); m_parser.incOffset())
		*pch++ = m_parser.getSymb();

	*pch = '\0';
	return(0);
	}
/* ======================================================================= */
// extracts parameter, numerical param
int RtfParser::Params::extractParams(
		int				*pnParam,
		int				*pbParam)	{
	// 2005.08.17

	bool isNeg		= false;
	int nParam		= 0;
	int bParam		= 0;

	if ('-' == m_parser.getSymb())
		{
		isNeg  = true;
		if (EOF == m_parser.incOffset())
			return(ecEndOfFile);
		}

	if (isdigit(m_parser.getSymb()))
		{
		bParam	= 1;
		// a digit after the control means we have a parameter

		std::string param;

		int ch	= m_parser.getSymb();
		while(isdigit(ch))
			{
			param.append(1, ch);

			m_parser.incOffset();
			ch	= m_parser.getSymb();
			}

		nParam	= CConvertStr::toInt(param);

		if (isNeg)
			nParam = -nParam;
		}

	if (' ' == m_parser.getSymb())
		m_parser.incOffset();

	if (pnParam)	*pnParam	= nParam;
	if (pbParam)	*pbParam	= bParam;
	return(0);
	}
/* ======================================================================= */
// extracts keyword & parameter
void RtfParser::Params::extractKeywordAndParams(
		char			*szKeyword,
		int				*pnParam,
		int				*pbParam)	{
	// 2005.08.17
	RtfParser::Params::extractKeyword(szKeyword);
	RtfParser::Params::extractParams(pnParam, pbParam);
	}
/* ======================================================================= */
//
// %%Function: RtfParser::ParseEsc
//
// Step 2:
// get a control word (and its associated value) and
// call RtfParser::process to dispatch the control.
//

// parses a keyword
int RtfParser::Params::process()	{
	// 2005.08.18
	int nErr;
	int nParam;
	int bParam;
	char szKeyword[30];

	extractKeywordAndParams(szKeyword, &nParam, &bParam);

	RtfParser::Keywords	kwd(m_parser);

	nErr	= kwd.process(szKeyword, nParam, bParam);
	return(nErr);
	}
/* ======================================================================= */
