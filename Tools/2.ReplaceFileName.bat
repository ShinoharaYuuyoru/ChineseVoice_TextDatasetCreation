@echo off

title Replace File Name Bat.

echo.

echo This batch can replace any symbol which is in the file name.

echo.

echo.&set /p strtemp3= Please input file type��

echo.&set /p strtemp1= Please input the string you want to be replaced��including SPACE����

echo.&set /p strtemp2= Please input the string you want to replace��ENTER to Delete����

setlocal enabledelayedexpansion

for /f "delims=" %%a in ('dir /a /b *.%strtemp3%') do (

set FNStr=%%a

ren "%%~a" "!FNStr:%strtemp1%=%strtemp2%!")

echo.

echo Finished.

echo.

pause