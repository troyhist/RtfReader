/* =======================================================================
// RTF Processor ver. 1.0 ("C++")
// vector conversion
// -----------------------------------------------------------------------
// CD: 2005.11.11
// -----------------------------------------------------------------------
//    Compiler: MS VC 6.0
// Application: WIN32
//   Edited by: Sergey Kolevatov
// =======================================================================
// RtfVect_f.h: implementation of service functions
// ======================================================================= */
#include "../RtfElem/RtfVect_f.h"		// prototypes self-control
// ======================================================================= */
#define INCL_H_HARD_ASSERT	// _HARD_ASSERT_
#include "../lib_path.h"	// ...
/* ======================================================================= */
// imports a tagRTFFILE and converts it into 'RtfElemVect'
RtfElemVect RtfVect_import(
		const tagRTFFILE	*patElems)	{
	// 2005.11.11

	RtfElemVect	atRes;

	for (int i=0; i<RTFFILE_size(patElems); i++)
		atRes.push_back(*RTFFILE_at(patElems, i));

	return(atRes);
	}
/* ======================================================================= */
