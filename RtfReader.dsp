# Microsoft Developer Studio Project File - Name="RtfReader" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=RtfReader - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "RtfReader.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "RtfReader.mak" CFG="RtfReader - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "RtfReader - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "RtfReader - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "RtfReader - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "RtfReader - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "RtfReader - Win32 Release"
# Name "RtfReader - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "TCI"

# PROP Default_Filter ""
# Begin Source File

SOURCE=N:\DoktorArbeit\Projects\TCILIB\FUNC\FILEIO\f_fileio.c
# End Source File
# End Group
# Begin Group "RTFPROC"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\RtfProc\rtf_f_dump.c
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtf_f_extrkwd.c
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtf_f_hex.c
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtf_f_kern.c
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtf_f_kwd.c
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtf_f_wrap.c
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtfproc.c
# End Source File
# End Group
# Begin Source File

SOURCE=.\main.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "TCI_H"

# PROP Default_Filter ""
# Begin Group "HWCOOP_H"

# PROP Default_Filter ""
# Begin Source File

SOURCE=N:\DoktorArbeit\Projects\TCILIB\HWTAIL\x_malloc.h
# End Source File
# Begin Source File

SOURCE=N:\DoktorArbeit\Projects\TCILIB\HWTAIL\x_stdio.h
# End Source File
# End Group
# Begin Source File

SOURCE=N:\DoktorArbeit\Projects\TCILIB\FUNC\FILEIO\f_fileio.h
# End Source File
# Begin Source File

SOURCE=N:\DoktorArbeit\Projects\TCILIB\FUNC\BUN\f_tcilib_bun.h
# End Source File
# Begin Source File

SOURCE=N:\DoktorArbeit\Projects\TCILIB\tcilib_path.h
# End Source File
# End Group
# Begin Group "RTFPROC_H"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\RtfProc\rtf_f_dump.h
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtf_f_errc.h
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtf_f_extrkwd.h
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtf_f_hex.h
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtf_f_kern.h
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtf_f_kwd.h
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtf_f_wrap.h
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtf_t.h
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtfproc.h
# End Source File
# Begin Source File

SOURCE=.\RtfProc\rtftype.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\lib_path.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
