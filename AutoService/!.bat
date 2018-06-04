@echo off
set M_PRJ_NAME=RtfParser
set M_BU=C:\Kolevatov\BACKUP\ProjectsB\%M_PRJ_NAME%
set M_BU2=N:\ProjectsB\%M_PRJ_NAME%
echo.
echo %M_PRJ_NAME% ver. 1.0 (22.07.2003)
if %1.==. goto nocom
echo on
call !A_SRC #0105 ..\ %M_PRJ_NAME%_ %1 ..\LastBackup.h !exclude.txt %M_BU% %M_BU2% %2
@echo off
goto end
:nocom
echo Type Build number !!! Ex: !makeres 10
:end
