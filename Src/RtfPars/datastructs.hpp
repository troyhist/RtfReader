#ifndef _datastructs_t_H_
#define _datastructs_t_H_

typedef struct char_prop
	{
	char fBold;
	char fUnderline;
	char fItalic;
	} CHP;                  // CHaracter Properties

typedef enum _JUST {justL, justR, justC, justF } JUST;
typedef struct para_prop
	{
	int xaLeft;                 // left indent in twips
	int xaRight;                // right indent in twips
	int xaFirst;                // first line indent in twips
	JUST just;                  // justification
	} PAP;                  // PAragraph Properties

typedef enum _SBK {sbkNon, sbkCol, sbkEvn, sbkOdd, sbkPg} SBK;
typedef enum _PGN {pgDec, pgURom, pgLRom, pgULtr, pgLLtr} PGN;
typedef struct sect_prop
	{
	int cCols;                  // number of columns
	SBK sbk;                    // section break type
	int xaPgn;                  // x position of page number in twips
	int yaPgn;                  // y position of page number in twips
	PGN pgnFormat;              // how the page number is formatted
	} SEP;                  // SEction Properties

typedef struct doc_prop
	{
	int xaPage;                 // page width in twips
	int yaPage;                 // page height in twips
	int xaLeft;                 // left margin in twips
	int yaTop;                  // top margin in twips
	int xaRight;                // right margin in twips
	int yaBottom;               // bottom margin in twips
	int pgnStart;               // starting page number in twips
	char fFacingp;              // facing pages enabled?
	char fLandscape;            // landscape or portrait??
	} DOP;                  // DOcument Properties

typedef enum _RDS { rdsNorm, rdsSkip } RDS;              // Rtf Destination State
typedef enum _RIS { risNorm, risBin, risHex } RIS;       // Rtf Internal State

typedef struct save             // property save structure
	{
	struct save *pNext;         // next save
	CHP chp;
	PAP pap;
	SEP sep;
	DOP dop;
	RDS rds;
	RIS ris;
	} SAVE;

// What types of properties are there?
typedef enum _IPROP {
	ipropBold, ipropItalic, ipropUnderline, ipropLeftInd,
	ipropRightInd, ipropFirstInd, ipropCols, ipropPgnX,
	ipropPgnY, ipropXaPage, ipropYaPage, ipropXaLeft,
	ipropXaRight, ipropYaTop, ipropYaBottom, ipropPgnStart,
	ipropSbk, ipropPgnFormat, ipropFacingp, ipropLandscape,
	ipropJust, ipropPard, ipropPlain, ipropSectd,
	ipropMax } IPROP;

typedef enum _ACTN {actnSpec, actnByte, actnWord} ACTN;
typedef enum _PROPTYPE {propChp, propPap, propSep, propDop} PROPTYPE;

typedef struct propmod
	{
	ACTN actn;              // size of value
	PROPTYPE prop;          // structure containing value
	int  offset;            // offset of value from base of structure
	} PROP;

typedef enum _IPFN {ipfnBin, ipfnHex, ipfnSkipDest } IPFN;
typedef enum _IDEST {idestPict, idestSkip } IDEST;
typedef enum _KWD {kwdChar, kwdDest, kwdProp, kwdSpec} KWD;

typedef struct symbol
	{
	char *szKeyword;        // RTF keyword
	int  dflt;              // default value to use
	bool fPassDflt;         // true to use default value from this table
	KWD  kwd;               // base action to take
	int  idx;               // index into property table if kwd == kwdProp
							// index into destination table if kwd == kwdDest
							// character to print if kwd == kwdChar
	} SYM;


#endif	// _datastructs_t_H_
