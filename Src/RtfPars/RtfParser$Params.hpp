
#ifndef _RtfParser_Params_HPP_
#define _RtfParser_Params_HPP_


class RtfParser;

class RtfParser::Params
{
	// Construction:
	public:
	
	// rtf parser kernel
	RtfParser::Params(
			RtfParser	&parser);

	private:
		RtfParser::Params(const RtfParser::Params&);
		RtfParser::Params& operator=(const RtfParser::Params&);

	// Properties:
	public:

	// Operations:
	public:
		int process();

	// Implementation:
	private:

		// extracts parameter, keyword
		int RtfParser::Params::extractKeyword(
				char			*szKeyword);

		// extracts parameter, numerical param
		int RtfParser::Params::extractParams(
				int				*pnParam,
				int				*pbParam);

		// extracts keyword & parameter
		void RtfParser::Params::extractKeywordAndParams(
				char			*szKeyword,
				int				*pnParam,
				int				*pbParam);

		RtfParser	&m_parser;
};

#endif	// _RtfParser_Params_HPP_
