/* =======================================================================
// RTF Parser ver. 1.0 ("C")
// "C++" class like wrapping functions
// -----------------------------------------------------------------------
// CD: 2005.08.19
// -----------------------------------------------------------------------
//    Compiler: MS VC 6.0
// Application: WIN32
//   Edited by: Sergey Kolevatov
// =======================================================================
// RtfParser.cpp: implementation of service functions
// ======================================================================= */
#include "../RtfPars/RtfParser.hpp"				// self

#include "../RtfPars/RtfParser$Kernel.hpp"		// RtfParser$Kernel
#include "../RtfPars/parsererr_t.h"		// errorcodes: ec...


/* ======================================================================= */
/* INTERN */
/* ======================================================================= */
// returns '1' if parser is in skipping mode
bool RtfParser::isSkipping() const	{
	// 2005.08.17
	return(this->m_bSkipMode);
	}
// -----------------------------------------------------------------------
// sets/resets skip mode
void RtfParser::setSkip(
		const bool			b)	{
	this->m_bSkipMode	= b;
	}
/* ======================================================================= */
// returns 'SkipDestIfUnk' flag
bool RtfParser::getSkipDestIfUnk() const	{
	// 2005.08.17
	return(this->m_bSkipDestIfUnkX);
	}
// -----------------------------------------------------------------------
// sets/resets 'SkipDestIfUnk' flag
void RtfParser::setSkipDestIfUnk(
		const bool			b)	{
	this->m_bSkipDestIfUnkX	= b;
	}
/* ======================================================================= */
// returns current counter value
int RtfParser::getOffs() const	{
	// 2005.08.18
	return(this->m_curOffset);
	}
/* ======================================================================= */
// defines block start position
void RtfParser::setBlkStart(
		const int		nOffset)	{
	// 2005.08.19
	this->m_blockStartPos	= nOffset;
	}
// -----------------------------------------------------------------------
// defines block stop position
void RtfParser::setBlkStop(
		const int		nOffset)	{
	// 2005.08.19
	this->m_blockStopPos	 = nOffset;
	}
/* ======================================================================= */
// adds given shift value to offset
int RtfParser::addOffset(
		const int		nOffsShift)	{
	// 2005.08.18
	if (this->m_curOffset + nOffsShift < this->m_size)
		{
		this->m_curOffset	+= nOffsShift;
		return(0);
		}
	this->m_curOffset	= this->m_buf.size();
	return(RtfParser::EOFF);
	}
/* ======================================================================= */
// increases read offset
int RtfParser::incOffset()	{
	// 2005.08.17
	return(addOffset(1));
	}
/* ======================================================================= */
// returns a symbol at current offset
int RtfParser::getSymb() const	{
	// 2005.08.17
	return(this->m_buf.at(this->m_curOffset));
	}
/* ======================================================================= */
// returns data buffer
const std::string& RtfParser::getBuf() const	{
	return(this->m_buf);
	}
/* ======================================================================= */
/* PUBLIC */
/* ======================================================================= */
// inits parser structure
RtfParser::RtfParser(
		const std::string	&buf,
		IRtfPrinter			&printer,
		const int			nPrnPar):
		m_buf(buf),
		m_printer(printer)	{
	// 2005.08.15
	// 2005.10.27 - added 'nPrnPar'

	this->m_size				= m_buf.size();
	this->m_curOffset			= 0;
	this->m_bSkipMode			= false;
	this->m_bSkipDestIfUnkX		= false;

	this->m_stackSize			= 0;
	
	// sets default block type a CTRL
	this->m_blockType			= RTF_BLKTYPE_CTRL;

	// defines a zero length block
	this->m_blockStartPos		= 0;
	this->m_blockStopPos		= 0;
	}
/* ======================================================================= */
// Rtf parser
int RtfParser::parse()	{
	// 2005.10.27

	RtfParser::Kernel	kern(*this);

	int ec	= kern.parse();

	if (ecOK != ec)
		return(ec);

	if (this->m_stackSize < 0)
		return(ecStackUnderflow);

	if (this->m_stackSize > 0)
		return(ecUnmatchedBrace);

	return(ecOK);
	}
/* ======================================================================= */
void RtfParser::printCurrBlock()	{
	
	std::string block	= m_buf.substr(m_blockStartPos, m_blockStopPos - m_blockStartPos);

	m_printer.handle(
		m_blockType,
		RTF_BLKTYPE_CTRL == m_blockType || m_bSkipMode,
		block);
}
/* ======================================================================= */
