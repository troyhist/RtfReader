
#include "../RtfElemC/RtfCodec.hpp"		// prototypes self-control

#include "../RtfElemC/CStrEsc.hpp"		// CStrEsc::isHex


/* ======================================================================= */
// decodes ESC-sequences in given src-string
void RtfCodec::decode(
		std::string			&dest,
		const std::string	&src)	{
	// 2005.08.17
	// 2005.10.27 - implemented as a decoder
	// 2008.01.31 - reimplemented C++

	dest.clear();

	int srcLen	= (int)src.size();

	for (int i=0; i<srcLen; ++i)
		{
		int c	= src.at(i);

		if ('\\' == c)
			{
			std::string	subStr	= src.substr(i, 4);

			if (CStrEsc::isHex(subStr))
				{
				int ch	= CStrEsc::decodeEscValue(subStr);
				dest.append(1, ch);
				i	+= 3;
				}
			}
		else
			{
			dest.append(1, c);
			}
		}

	}
/* ======================================================================= */
// encodes a text string into an RTF string w. ESC-sequences
void RtfCodec::encode(
		std::string			&dest,
		const std::string	&src)	{
	// 2005.10.27
	// 2008.01.31 - reimplemented C++

	dest.clear();

	int srcLen	= (int)src.size();

	for (int i=0; i<srcLen; ++i)
		{
		int ch	= src.at(i);

		if (!CStrEsc::isAscii(ch))
			{
			std::string temp;
			CStrEsc::encodeEscValue(temp, ch);
			dest.append(temp);
			}
		else
			{
			dest.append(1, ch);
			}

		}
	}
