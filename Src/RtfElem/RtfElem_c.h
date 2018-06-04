/* =======================================================================
// RTF Processor ver. 1.0 ("C++")
// file elements processing
// -----------------------------------------------------------------------
// CD: 2005.11.10
// -----------------------------------------------------------------------
//    Compiler: MS VC 6.0
// Application: WIN32
//   Edited by: Sergey Kolevatov
// =======================================================================
// RtfElem_c.h: implementation of service functions
// ======================================================================= */
#ifndef _RTFELEM_C_H_
#define _RTFELEM_C_H_
/* ======================================================================= */
#define INCL_H_HARD_ASSERT	// _HARD_ASSERT_
#include "../lib_path.h"	// ...

#include <memory.h>						// memcpy
#include <stdio.h>						// FILE
/* ======================================================================= */
class	CRtfElem
	{
	public:

	// def ctor
	CRtfElem()	{
		}

	// init ctor
	CRtfElem(
		const tagRTFFILE_EL		&rtElem)	{
		
		m_nType	= rtElem.m_nType;
		m_bSkip	= rtElem.m_bSkip;
	
		char *sBuf	= new char[rtElem.m_nSize + 1];
		memcpy(sBuf, rtElem.m_sStr, rtElem.m_nSize);
		sBuf[rtElem.m_nSize]	= 0;
		m_tsStr = sBuf;
		delete[] sBuf;
		}

	// dtor
	~CRtfElem()	{
		}

	// returns '1' if given element contains text
	bool isText()	const {
		return(!m_bSkip);
		}

	// returns undecoded text string
	x_CString getText()	const {
		return(m_tsStr);
		}
	
	// extract text from given element and converts it to CString
	x_CString getDecodedText()	const {
		return(m_bSkip?m_tsStr:RtfStr_decodeEsc(m_tsStr));
		}

	// saves the RTF element into given file (used 'fp')
	void save(
			void					*fp) const	{
		// 2005.10.27
		// 2005.11.11 - C++ version
		int nSize	= m_tsStr.GetLength();
		fwrite(&m_nType, 1, sizeof(m_nType), (FILE*)fp);
		fwrite(&m_bSkip, 1, sizeof(m_bSkip), (FILE*)fp);
		fwrite(&nSize, 1, sizeof(nSize), (FILE*)fp);
		fwrite(m_tsStr.c_str(), 1, nSize, (FILE*)fp);
		}

	// saves the RTF element into given file as a text(used 'fp')
	void saveAsText(
			void					*fp) const	{
		// 2005.10.27
		// 2005.11.11 - C++ version
		fwrite(m_tsStr.c_str(), 1, m_tsStr.GetLength(), (FILE*)fp);
		}

	// loads the RTF element from given file (used 'fp')
	void load(
			void					*fp)	{
		// 2005.10.27
		// 2005.11.11 - C++ version
		int		nSize;
		char	*sStr;

		fread(&m_nType, 1, sizeof(m_nType), (FILE*)fp);
		fread(&m_bSkip, 1, sizeof(m_bSkip), (FILE*)fp);
		fread(&nSize, 1, sizeof(nSize), (FILE*)fp);
		
		_HARD_ASSERT_(nSize > 0 && nSize <= 32 * 1024);

		sStr	= new char[nSize + 1];

		fread(sStr, 1, nSize, (FILE*)fp);
		sStr[nSize]	= 0;
		m_tsStr	= sStr;
		delete[] sStr;
		}

	// sets unencoded text string
	void setText(
			const x_CString			&rtsStr)	{
		m_tsStr	= rtsStr;
		}

	// sets text extracted from CString into given element
	void setTextEnc(
			const x_CString			&rtsStr)	{
		m_tsStr	= m_bSkip?rtsStr:RtfStr_encodeEsc(rtsStr);
		}

	private:
		int				m_nType;	// type
		int				m_bSkip;	// skip flag (if not text)
		x_CString		m_tsStr;	// text
	};
/* ======================================================================= */
#endif	// _RTFELEM_C_H_
/* ======================================================================= */
