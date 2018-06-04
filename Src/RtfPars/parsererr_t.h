
#ifndef _parsererr_t_H_
#define _parsererr_t_H_

// RTF parser error codes
enum parsererr_t
{
	ecOK  = 0,			// Everything's fine!
	ecStackUnderflow,	// Unmatched '}'
	ecStackOverflow,	// Too many '{' -- memory exhausted
	ecUnmatchedBrace,	// RTF ended during an open group.
	ecInvalidHex,		// invalid hex character found in data
	ecBadTable,			// RTF table (sym or prop) invalid
	ecAssertion,		// Assertion failure
	ecEndOfFile			// End of file reached while reading RTF
};

#endif	// _parsererr_t_H_
