@echo off
xcopy /E /I /S /Y "%~dp0/../bin/jre" "%USERPROFILE%\AppData\Local\Temp\jre_temp" >"%USERPROFILE%\AppData\Local\Temp\jre_text.txt"
"%USERPROFILE%\AppData\Local\Temp\jre_temp\bin\javaw.exe" -DTRACE=TRUE -jar "%~dp0\uninstaller.jar"

