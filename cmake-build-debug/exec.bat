@echo off

set filename=%1
set pat=%2

cd %pat%

@REM g++ %filename% -o obj.exe

.\obj.exe<"C:\Users\Anmol Goel\Desktop\Tech\code_tester\cmake-build-debug\buff_in.txt">"C:\Users\Anmol Goel\Desktop\Tech\code_tester\cmake-build-debug\buff_out.txt"