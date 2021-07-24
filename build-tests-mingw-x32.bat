g++ -O0 -g tests/main.cpp  "-I%IRRKLANG_ROOT%/../x32/include"  -Llib/x32/mingw "-L%IRRKLANG_ROOT%/../x32/lib/Win32-gcc"  -lirrklang-proxy-debug -lirrKlang  -o tests/x32/main-mingw-debug.exe
g++ -O2 -g tests/main.cpp  "-I%IRRKLANG_ROOT%/../x32/include"  -Llib/x32/mingw "-L%IRRKLANG_ROOT%/../x32/lib/Win32-gcc"  -lirrklang-proxy-release -lirrKlang  -o tests/x32/main-mingw-release.exe
copy /b /v /y %IRRKLANG_ROOT%\..\x32\bin\win32-gcc\ikpFlac.dll tests\x32\
copy /b /v /y %IRRKLANG_ROOT%\..\x32\bin\win32-gcc\ikpMP3.dll tests\x32\
copy /b /v /y %IRRKLANG_ROOT%\..\x32\bin\win32-gcc\irrKlang.dll tests\x32\

