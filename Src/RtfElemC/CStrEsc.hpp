
#ifndef _CStrEsc_HPP_
#define _CStrEsc_HPP_

#include <string>

class CStrEsc
	{
	// Construction:
	public:	

	// Properties:
	public:

	// Operations:
	public:

		// returns '1' if given string starts w. a hex. number
		// (format \'XX)
		static bool isHex(const std::string &str);

		// returns '1' if character is ASCII character [32; 127]
		static bool isAscii(const int	ch);

		// extracts value of given hex number
		static int decodeEscValue(const std::string &str);

		
		// generates a hex value of given number in given buffer
		static void encodeEscValue(
				std::string	&str,
				const int	val);


	// Implementation:
	private:

		// returns 'true' if given character is a hex digit
		static bool isHexDigit(const int	c);
	};



#endif	// _CStrEsc_HPP_
