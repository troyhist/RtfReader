

#include "../RtfProc/RtfProc_f_parse.h"		// prototypes self-control
// ======================================================================= */
#include "../lib_path.h"		// 

#include "../RtfPars/RtfPars_f.h"		// RtfParser::RtfParser
#include "../RtfElemC/RtfVectC_f.h"		// tagRTFFILE
#include "../RtfElem/RtfVect_f.h"		// RtfVect_import
#include "../RtfProc/RtfProc_f.h"		// RtfProc_...

/* ======================================================================= */
// parser
int RtfProc_parse(
		RtfElemVect	&ratRtfElem,
		const char		*sBufIn,
		const int		nBufInSize)	{
	// 2005.10.27
	// 2005.11.11 - C++ version

	int nErr;
	RtfParser	tParser;
	tagRTFFILE		atElemsC;

	RTFFILE_init	(&atElemsC);

	RtfParser::RtfParser	(&tParser,
		sBufIn,
		nBufInSize,
		RtfVect_add,
		(int)&atElemsC);

	nErr	= RtfParser::parse		(&tParser);

	_HARD_ASSERT_(0 == nErr);
	
	ratRtfElem	= RtfVect_import	(&atElemsC);

	return(0);
	}
/* ======================================================================= */
