
#include "../RtfElemC/CStrEsc.hpp"		// self

#include <tcilib/src/syswrap/convert/CConvert.hpp>	// CConvert
#include <tcilib/src/syswrap/convert/CConvertStr.hpp>	// CConvertStr
#include <tcilib/Src/SysWrap/Format/CFormatter.hpp>		// CFormatter

/* ======================================================================= */
// returns 'true' if given character is a hex digit
bool CStrEsc::isHexDigit(
		const int	c)	{
	// 2005.08.18

	if (('a' <= c && c <= 'f') ||
		('A' <= c && c <= 'F') ||
		('0' <= c && c <= '9'))
		return true;

	return false;
	}
/* ======================================================================= */
// returns '1' if given string starts w. a hex. number
// (format \'XX)
bool CStrEsc::isHex(
		const std::string &str)	{
	// 2005.08.18

	if(0 != str.substr(0, 2).compare("\\'"))
		return false;

	for (int i=2; i<4; ++i)
		if(!isHexDigit(str.at(i)))
			return false;

	return true;
	}
/* ======================================================================= */
// returns '1' if character is ASCII character [32; 127]
bool CStrEsc::isAscii(
		const int	ch)	{
	// 2005.10.27
	if (32 <= ch && ch <= 127)
		return true;

	return false;
	}
/* ======================================================================= */
// extracts value of given hex number
int CStrEsc::decodeEscValue(
		const std::string	&str)	{
	// 2005.08.18

	int res	= CConvertStr::toInt(str.substr(2, 2));

	return(res);
	}
/* ======================================================================= */
// generates a hex value of given number in given buffer
void CStrEsc::encodeEscValue(
		std::string		&str,
		const int		val)	{
	// 2005.08.18
	str	= "\\'";

	GC_CString hexStr		= CConvert::toStringHex(val);
	GC_CString formattedStr	= CFormatter::formatNumber_HEX(
		hexStr, true, 2, false, 0, false, true, false, false);

	str.append(*formattedStr);
	}
/* ======================================================================= */
