/* =======================================================================
// RTF Processor ver. 1.0 ("C")
// functions
// -----------------------------------------------------------------------
// CD: 2005.10.24
// -----------------------------------------------------------------------
//    Compiler: MS VC 6.0
// Application: WIN32
//   Edited by: Sergey Kolevatov
// =======================================================================
// RtfProc_f.h: implementation of service functions
// ======================================================================= */
#ifndef _RTFPROC_F_H_
#define _RTFPROC_F_H_
/* ======================================================================= */
#include "../RtfElem/RtfElem_c.h"		// RtfElemVect
/* ======================================================================= */
// saves array of RTF elements into given file
// returns: '-1' - error
int RtfProc_save(
		const RtfElemVect	&ratElems,
		const char				*sFilename);

// saves array of RTF elements as a standard RTF file
// returns: '-1' - error
int RtfProc_saveT(
		const RtfElemVect	&ratElems,
		const char				*sFilename);

// dumps RTF elements
void RtfProc_dump(
		const RtfElemVect	&ratElems);
/* ======================================================================= */
#endif	// _RTFPROC_F_H_
/* ======================================================================= */
