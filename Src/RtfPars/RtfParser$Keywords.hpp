
#ifndef _RtfParser_Keywords_HPP_
#define _RtfParser_Keywords_HPP_


class RtfParser;

class RtfParser::Keywords
{
	// Construction:
	public:
	
	// rtf parser kernel
	RtfParser::Keywords(
			RtfParser	&parser);

	private:
		RtfParser::Keywords(const RtfParser::Keywords&);
		RtfParser::Keywords& operator=(const RtfParser::Keywords&);

	// Properties:
	public:

	// Operations:
	public:
		int RtfParser::Keywords::process(
			char			*szKeyword,
			int				nParam,
			int				bParam);

	// Implementation:
	private:
		// return an inxed of given kwd, or '-1'
		int getKwdIdx(
				const char		*szKeyword);
		// returns '1' if destination may be skipped
		int canSkipDest(
				const int	nIdx);
		// returns '1' if given KWD is 'bin'
		int isKwdBin(
				const char	*sKeyword);

		RtfParser	&m_parser;
};

#endif	// _RtfParser_Keywords_HPP_
