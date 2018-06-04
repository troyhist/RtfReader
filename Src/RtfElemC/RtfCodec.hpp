
// 2008.01.31

#ifndef _RtfCodec_HPP_
#define _RtfCodec_HPP_

#include <string>

class RtfCodec
	{
	// decodes ESC-sequences in given src-string
	static void decode(
			std::string			&dest,
			const std::string	&src);

	// encodes a text string into an RTF string w. ESC-sequences
	static void encode(
			std::string			&dest,
			const std::string	&src);

	};
/* ======================================================================= */
#endif	// _RtfCodec_HPP_
/* ======================================================================= */
