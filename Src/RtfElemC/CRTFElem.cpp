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
// RtfElemC_f.c: implementation of service functions
// ======================================================================= */

// 2007.09.03

#include "../RtfElemC/CRTFElem.hpp"		// self
/* ======================================================================= */

// Construction:
CRTFElem::CRTFElem(
		const int				type,
		const bool				mustSkip,
		const int				size,
		const std::string		&str)	{
	// 2005.10.27
	this->m_type		= type;
	this->m_mustSkip	= mustSkip;
	this->m_size		= size;
	this->m_str			= str;
	}
/* ======================================================================= */
// copy constructor
CRTFElem::CRTFElem(const CRTFElem &r)	{
	// 2005.10.27
	this->m_type		= r.m_type;
	this->m_mustSkip	= r.m_mustSkip;
	this->m_size		= r.m_size;
	this->m_str			= r.m_str;
	}
/* ======================================================================= */
CRTFElem& CRTFElem::operator=(const CRTFElem &r)	{
	// 2008.01.30
	if(&r == this) return *this;

	this->m_type		= r.m_type;
	this->m_mustSkip	= r.m_mustSkip;
	this->m_size		= r.m_size;
	this->m_str			= r.m_str;

	return *this;
	}
/* ======================================================================= */
