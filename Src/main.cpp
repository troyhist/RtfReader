#include <stdio.h>			// printf
#include <stdlib.h>			// free

//#define INCL_F_FILEIO
//#include "./lib_path.h"		// fload

#include "./RtfElem/RtfVect_f.h"		// RtfVect_import
#include "./RtfProc/RtfProc_f.h"		// RtfProc_...
#include "./RtfProc/RtfProc_f_parse.h"	// RtfProc_parse

#include <string>
#include <tcilib/src/syswrap/convert/CConvertStrA.hpp>	// CConvertStrA
#include <tcilib/src/syswrap/fileio/CFileLoader.hpp>	// CFileLoader
#include <tcilib/src/syswrap/fileio/CTextLoader.hpp>	// CTextLoader

std::wstring;
tstring;
/* ======================================================================= */
// parser
void RtfReader_Parse(
		const std::string	&bufIn,
		const std::string	fileOut)	{
	// 2005.10.27
	// 2005.11.11 - C++ version
	
	RtfElemVect		rtfElems;

	RtfProc_parse	(rtfElems, bufIn, nBufInSize);
	
	RtfProc_save	(rtfElems, fileOut);

	printf("--- BEGIN DUMP ---\n");
	
	RtfProc_dump	(rtfElems);

	printf("\n"
		"--- END ---\n");

	return(0);
	}
/* ======================================================================= */
//
// %%Function: main
//
// Main loop. Initialize and parse RTF.
//
int main(int argc, char *argv[])
	{

	cout << "\n"
		"RtfReader DEMO ver. 1.0\n"
		"\n";
	if (4 != argc)
		{
		cout << 
			"USAGE: RtfReader <mode> <input.rtf> <output.txt>\n"
			"       mode   - RTF file processing mode\n"
			"       input  - input RTF file\n"
			"       output - output file\n"
			"\n"
			"Available modes:\n"
			"0 - parse & dump RTF file\n"
			"1 - extract text\n"
			"2 - extract controls\n"
			"\n";
		return 0;
		}
	
	int mode	= CConvertStrA::toInt(argv[1]);

	std::string fileIn		= argv[2];
	std::string fileOut		= argv[3];

	cout <<
		"       Mode: " << mode << endl <<
		" Input File: " << fileIn  << endl <<
		"Output File: " << fileOut << endl << endl;

	char	*bufIn;
	long	size;
	long	readButes;

	CTextLoader:: :fload(bufIn, size, readBytes, fileIn, false);

	if (0)
		{
		printf("\n"
			"ERROR: cannot load file '%s'\n"
			"\n",
			sFileIn);
		return(1);
		}

	printf(" Read bytes: %d (%d buf size)\n"
		"\n",
		readBytes,
		size);

	
	int ec = RtfReader_Parse(bufIn, readBytes, sFileOut);

	if (0 != ec)
        printf("error %d parsing rtf\n",
			ec);
    else
        printf("Parsed RTF file OK\n");

    free(sBufIn);
    return 0;
	}
/* ======================================================================= */
