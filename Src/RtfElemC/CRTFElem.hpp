/* =======================================================================
// RTF Processor ver. 1.0 ("C")
// file elements processing
// -----------------------------------------------------------------------
// CD: 2005.10.24
// -----------------------------------------------------------------------
//    Compiler: MS VC 6.0
// Application: WIN32
//   Edited by: Sergey Kolevatov
// =======================================================================
// CRTFElem.hpp: implementation of service functions
// ======================================================================= */
/* ======================================================================= */
#ifndef _CRTFElem_HPP_
#define _CRTFElem_HPP_

#include <string>

/**
RTF file element
*/

class CRTFElem
	{
	// Construction:
	public:	
		CRTFElem(
			const int				type,
			const bool				mustSkip,
			const int				size,
			const std::string		&str);

		CRTFElem(const CRTFElem&);

		CRTFElem& operator=(const CRTFElem&);

	// Properties:
	public:

		// returns 'true' if given element contains text
		bool isText() const;

		// returns raw text string
		const std::string& getText() const;

		// extract text from given element and converts it to CString
		std::string getDecodedText() const;


	// Operations:
	public:

	// Implementation:
	private:
		int			m_type;		// element type
		bool		m_mustSkip;	// "skip" flag
		int			m_size;		// data size
		std::string m_str;		// ptr to data
	};
/* ======================================================================= */
#endif	// _CRTFElem_HPP_
/* ======================================================================= */
