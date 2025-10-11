@echo off
title run.bat
cls

REM youtube_embed_url.exe

set /p start="start="
echo %start%

set /p stop="stop="
echo %stop%

set /p url="url="
echo %url%
REM pause

del output.txt
youtube_embed_url.exe %start% %stop% %url%

@echo on
