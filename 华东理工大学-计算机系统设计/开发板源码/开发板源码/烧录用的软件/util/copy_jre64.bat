@echo off
%windir%\System32\xcopy /y /I /S "%cd%/jre" "%~dp0/../bin/jre"

