
#include "../RtfPars/RtfParser.hpp"				// RtfParser
#include "../RtfPars/RtfParser$Keywords.hpp"	// prototypes self-control

#include <string.h>			// strcmp
#include <stddef.h>			// offsetof

#include "../RtfPars/parsererr_t.h"		// errorcodes: ec...
#include "../RtfPars/datastructs.hpp"		// errorcodes: ec...
/* ======================================================================= */
// RTF parser tables
/* ======================================================================= */
// Property descriptions
const PROP gl_const_atRgProp [ipropMax] = {
	actnByte,   propChp,    offsetof(CHP, fBold),       // ipropBold
	actnByte,   propChp,    offsetof(CHP, fItalic),     // ipropItalic
	actnByte,   propChp,    offsetof(CHP, fUnderline),  // ipropUnderline
	actnWord,   propPap,    offsetof(PAP, xaLeft),      // ipropLeftInd
	actnWord,   propPap,    offsetof(PAP, xaRight),     // ipropRightInd
	actnWord,   propPap,    offsetof(PAP, xaFirst),     // ipropFirstInd
	actnWord,   propSep,    offsetof(SEP, cCols),       // ipropCols
	actnWord,   propSep,    offsetof(SEP, xaPgn),       // ipropPgnX
	actnWord,   propSep,    offsetof(SEP, yaPgn),       // ipropPgnY
	actnWord,   propDop,    offsetof(DOP, xaPage),      // ipropXaPage
	actnWord,   propDop,    offsetof(DOP, yaPage),      // ipropYaPage
	actnWord,   propDop,    offsetof(DOP, xaLeft),      // ipropXaLeft
	actnWord,   propDop,    offsetof(DOP, xaRight),     // ipropXaRight
	actnWord,   propDop,    offsetof(DOP, yaTop),       // ipropYaTop
	actnWord,   propDop,    offsetof(DOP, yaBottom),    // ipropYaBottom
	actnWord,   propDop,    offsetof(DOP, pgnStart),    // ipropPgnStart
	actnByte,   propSep,    offsetof(SEP, sbk),         // ipropSbk
	actnByte,   propSep,    offsetof(SEP, pgnFormat),   // ipropPgnFormat
	actnByte,   propDop,    offsetof(DOP, fFacingp),    // ipropFacingp
	actnByte,   propDop,    offsetof(DOP, fLandscape),  // ipropLandscape
	actnByte,   propPap,    offsetof(PAP, just),        // ipropJust
	actnSpec,   propPap,    0,                          // ipropPard
	actnSpec,   propChp,    0,                          // ipropPlain
	actnSpec,   propSep,    0,                          // ipropSectd
	};
/* ======================================================================= */
// Keyword descriptions
const SYM gl_const_atRgSymRtf[] = {
//  keyword     dflt    fPassDflt   kwd         idx
	"b",        1,      false,     kwdProp,    ipropBold,
	"u",        1,      false,     kwdProp,    ipropUnderline,
	"i",        1,      false,     kwdProp,    ipropItalic,
	"li",       0,      false,     kwdProp,    ipropLeftInd,
	"ri",       0,      false,     kwdProp,    ipropRightInd,
	"fi",       0,      false,     kwdProp,    ipropFirstInd,
	"cols",     1,      false,     kwdProp,    ipropCols,
	"sbknone",  sbkNon, true,      kwdProp,    ipropSbk,
	"sbkcol",   sbkCol, true,      kwdProp,    ipropSbk,
	"sbkeven",  sbkEvn, true,      kwdProp,    ipropSbk,
	"sbkodd",   sbkOdd, true,      kwdProp,    ipropSbk,
	"sbkpage",  sbkPg,  true,      kwdProp,    ipropSbk,
	"pgnx",     0,      false,     kwdProp,    ipropPgnX,
	"pgny",     0,      false,     kwdProp,    ipropPgnY,
	"pgndec",   pgDec,  true,      kwdProp,    ipropPgnFormat,
	"pgnucrm",  pgURom, true,      kwdProp,    ipropPgnFormat,
	"pgnlcrm",  pgLRom, true,      kwdProp,    ipropPgnFormat,
	"pgnucltr", pgULtr, true,      kwdProp,    ipropPgnFormat,
	"pgnlcltr", pgLLtr, true,      kwdProp,    ipropPgnFormat,
	"qc",       justC,  true,      kwdProp,    ipropJust,
	"ql",       justL,  true,      kwdProp,    ipropJust,
	"qr",       justR,  true,      kwdProp,    ipropJust,
	"qj",       justF,  true,      kwdProp,    ipropJust,
	"paperw",   12240,  false,     kwdProp,    ipropXaPage,
	"paperh",   15480,  false,     kwdProp,    ipropYaPage,
	"margl",    1800,   false,     kwdProp,    ipropXaLeft,
	"margr",    1800,   false,     kwdProp,    ipropXaRight,
	"margt",    1440,   false,     kwdProp,    ipropYaTop,
	"margb",    1440,   false,     kwdProp,    ipropYaBottom,
	"pgnstart", 1,      true,      kwdProp,    ipropPgnStart,
	"facingp",  1,      true,      kwdProp,    ipropFacingp,
	"landscape",1,      true,      kwdProp,    ipropLandscape,

	"par",      0,      false,     kwdChar,    0x0a,
	"\0x0a",    0,      false,     kwdChar,    0x0a,
	"\0x0d",    0,      false,     kwdChar,    0x0a,
	"tab",      0,      false,     kwdChar,    0x09,
	"ldblquote",0,      false,     kwdChar,    '"',
	"rdblquote",0,      false,     kwdChar,    '"',

	"bin",      0,      false,     kwdSpec,    ipfnBin,
	"*",        0,      false,     kwdSpec,    ipfnSkipDest,
	"'",        0,      false,     kwdSpec,    ipfnHex,

	"author",   0,      false,     kwdDest,    idestSkip,
	"buptim",   0,      false,     kwdDest,    idestSkip,
	"colortbl", 0,      false,     kwdDest,    idestSkip,
	"comment",  0,      false,     kwdDest,    idestSkip,
	"creatim",  0,      false,     kwdDest,    idestSkip,
	"doccomm",  0,      false,     kwdDest,    idestSkip,
	"fonttbl",  0,      false,     kwdDest,    idestSkip,
	"footer",   0,      false,     kwdDest,    idestSkip,
	"footerf",  0,      false,     kwdDest,    idestSkip,
	"footerl",  0,      false,     kwdDest,    idestSkip,
	"footerr",  0,      false,     kwdDest,    idestSkip,
	"footnote", 0,      false,     kwdDest,    idestSkip,
	"ftncn",    0,      false,     kwdDest,    idestSkip,
	"ftnsep",   0,      false,     kwdDest,    idestSkip,
	"ftnsepc",  0,      false,     kwdDest,    idestSkip,
	"header",   0,      false,     kwdDest,    idestSkip,
	"headerf",  0,      false,     kwdDest,    idestSkip,
	"headerl",  0,      false,     kwdDest,    idestSkip,
	"headerr",  0,      false,     kwdDest,    idestSkip,
	"info",     0,      false,     kwdDest,    idestSkip,
	"keywords", 0,      false,     kwdDest,    idestSkip,
	"operator", 0,      false,     kwdDest,    idestSkip,
	"pict",     0,      false,     kwdDest,    idestSkip,
	"printim",  0,      false,     kwdDest,    idestSkip,
	"private1", 0,      false,     kwdDest,    idestSkip,
	"revtim",   0,      false,     kwdDest,    idestSkip,
	"rxe",      0,      false,     kwdDest,    idestSkip,
	"stylesheet",	0,	false,     kwdDest,    idestSkip,
	"subject",  0,      false,     kwdDest,    idestSkip,
	"tc",       0,      false,     kwdDest,    idestSkip,
	"title",    0,      false,     kwdDest,    idestSkip,
	"txe",      0,      false,     kwdDest,    idestSkip,
	"xe",       0,      false,     kwdDest,    idestSkip,
	"{",        0,      false,     kwdChar,    '{',
	"}",        0,      false,     kwdChar,    '}',
	"\\",       0,      false,     kwdChar,    '\\'
	};
const int gl_const_nIsymMax = sizeof(gl_const_atRgSymRtf) / sizeof(SYM);
/* ======================================================================= */
// rtf parser keywords
RtfParser::Keywords::Keywords(
		RtfParser	&parser):
	m_parser(parser)	{
	}
/* ======================================================================= */
// return an inxed of given kwd, or '-1'
int RtfParser::Keywords::getKwdIdx(
		const char		*szKeyword)	{
	// 2005.08.17
	int i;
	for (i = 0; i < gl_const_nIsymMax; i++)
		if (0 == strcmp(szKeyword, gl_const_atRgSymRtf[i].szKeyword))
			return(i);
	return(-1);
	}
/* ======================================================================= */
// returns '1' if destination may be skipped
int RtfParser::Keywords::canSkipDest(
		const int	nIdx)	{
	// 2005.08.18
	return(idestSkip == gl_const_atRgSymRtf[nIdx].idx);
	}
/* ======================================================================= */
// returns '1' if given KWD is 'bin'
int RtfParser::Keywords::isKwdBin(
		const char	*sKeyword)	{
	// 2005.08.17
	return(0==strcmp(sKeyword, "bin"));
	}
/* ======================================================================= */
//
// %%Function: RtfParser::process.
//
// Step 3.
// Search gl_const_atRgSymRtf for szKeyword and evaluate it appropriately.
//
// Inputs:
// szKeyword:   The RTF control to evaluate.
// param:       The parameter of the RTF control.
// fParam:      true if the control had a parameter; (that is, if param is valid)
//              false if it did not.
//
int RtfParser::Keywords::process(
		char			*szKeyword,
		int				nParam,
		int				bParam)	{
	// 2005.08.18
	int nIdx;

	// checks, whether current keyword is 'bin' keyword
	if (isKwdBin(szKeyword))
		{
		m_parser.addOffset(nParam);
		return(ecOK);
		}

	// search for szKeyword in gl_const_atRgSymRtf
	nIdx	= getKwdIdx(szKeyword);

	// control word not found
	if (-1 == nIdx)
		{
		// if this is a new destination skip the
		// destination else just discard it
		if (m_parser.getSkipDestIfUnk())
			m_parser.setSkip(true);

		m_parser.setSkipDestIfUnk(false);
		return(ecOK);
		}

	// control word found

	// checks, whether destination must be skipped
	if(canSkipDest(nIdx))
		m_parser.setSkip(true);

	return(ecOK);
//	return(ecBadTable);
	}
/* ======================================================================= */
