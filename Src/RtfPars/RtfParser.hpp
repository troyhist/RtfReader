
#ifndef _RtfParser_HPP_
#define _RtfParser_HPP_

#include <string>
#include "../RtfPars/IRtfPrinter.hpp"		// IRtfPrinter


class RtfParser
	{
	class Kernel;
	class Keywords;
	class Params;

	static const int EOFF	= -1;

	// block types, 2005.08.19
	enum blocktype_t
	{
	RTF_BLKTYPE_CTRL	= 0,	// control block
	RTF_BLKTYPE_TXT				// text block
	};

	// Construction:
	public:

		// inits parser structure
		RtfParser(
			const std::string	&buf,
			IRtfPrinter			&printer,
			const int			nPrnPar);

	// Properties:
	public:

	// Operations:
	public:

		// Rtf parser
		int parse();


	// Implementation:
	private:

		bool isSkipping() const;

		// sets/resets skip mode
		void setSkip(const bool b);

		// returns 'SkipDestIfUnk' flag
		bool getSkipDestIfUnk() const;

		// sets/resets 'SkipDestIfUnk' flag
		void setSkipDestIfUnk(const bool b);

		// returns current counter value
		int getOffs() const;

		// defines block start position
		void setBlkStart(
				const int			nOffset);
		// defines block stop position
		void setBlkStop(
				const int			nOffset);

		// defines "stop parsing" flag
		void setStop(
				const bool			bStop);

		// returns "stop parsing" flag
		bool getStop() const;

		// adds given shift value to offset
		int addOffset(
				const int			nOffsShift);

		// increases read offset
		int incOffset();

		// returns a symbol at current offset
		int getSymb() const;

		//// returns a ptr to current symbol
		//const char* getPtr() const;

		// returns data buffer
		const std::string& getBuf() const;

		void printCurrBlock();


		int				m_stackSize;

		bool			m_bSkipMode;		// skip mode
		bool			m_bSkipDestIfUnkX;	// skip destination if unknown
		int				m_curOffset;

		blocktype_t		m_blockType;		// current block type: 0 - ctrl, 1 - txt
		
		int				m_blockStartPos;	// block start position
		int				m_blockStopPos;		// a position of a symbol which comes just beyond the block

		const std::string	&m_buf;
		int				m_size;

		IRtfPrinter		&m_printer;			// printer function

	};

#endif	// _RtfParser_HPP_
