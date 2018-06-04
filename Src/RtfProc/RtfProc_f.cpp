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
#include "../RtfProc/RtfProc_f.h"		// prototypes self-control
// ======================================================================= */
#include <stdio.h>			// FILE
/* ======================================================================= */
//#define INCL_H_HARD_ASSERT	// _HARD_ASSERT_
#define INCL_NEW_C			// newc, deletec, 2005.10.28
#include "../lib_path.h"	// ...
/* ======================================================================= */
#include "../RtfElem/RtfElem_c.h"		// RtfElem_..., 2005.10.27
/* ======================================================================= */
/* INTERN */
/* ======================================================================= */
// saves array of RTF elements as a standard RTF file
// returns: '-1' - error
int RtfProc_I_save(
		const RtfElemVect	&ratElems,
		const char				*sFilename,
		const int				bNative)	{
	// 2005.10.27
	// 2005.11.11 - C++ version
	
	int nSize	= ratElems.size();
	FILE	*fp;

	fp	= fopen(sFilename, "wb");
	_HARD_ASSERT_(fp);

	if(!bNative)
		fwrite (&nSize, 1, sizeof(nSize), fp);

	for(size_t i=0; i<ratElems.size(); i++)
		{
		if(bNative)
			ratElems[i].saveAsText(fp);
		else
			ratElems[i].save(fp);
		}

	fclose(fp);
	return(0);
	}
/* ======================================================================= */
/* PUBLIC */
/* ======================================================================= */
// saves array of RTF elements into given file
// returns: '-1' - error
int RtfProc_save(
		const RtfElemVect	&ratElems,
		const char				*sFilename)	{
	// 2005.10.27
	return(RtfProc_I_save(ratElems, sFilename, 0));
	}
/* ======================================================================= */
// saves array of RTF elements as a standard RTF file
// returns: '-1' - error
int RtfProc_saveT(
		const RtfElemVect	&ratElems,
		const char				*sFilename)	{
	// 2005.10.27
	return(RtfProc_I_save(ratElems, sFilename, 1));
	}
/* ======================================================================= */
// dumps RTF elements
void RtfProc_dump(
		const RtfElemVect	&ratElems)	{
	// 2005.10.28
	// 2005.11.11 - C++ version
	
	for(size_t i=0; i<ratElems.size(); i++)
		{
		if(!ratElems[i].isText())
			continue;

		x_CString tsStr	= ratElems[i].getDecodedText();
	
		printf("%s\n", tsStr.c_str());
		}
	}
/* ======================================================================= */
