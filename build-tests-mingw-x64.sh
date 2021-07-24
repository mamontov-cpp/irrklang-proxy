g++ -O0 -g tests/main.cpp  -I$IRRKLANG_ROOT/../x64/include  -Llib/x64/mingw  -lirrklang-proxy-debug  -o tests/x64/main-mingw-debug.exe
g++ -O2 -g tests/main.cpp  -I$IRRKLANG_ROOT/../x64/include  -Llib/x64/mingw  -lirrklang-proxy-release  -o tests/x64/main-mingw-release.exe
cp -r lib/x64/mingw/irrklang-proxy-debug.dll tests/x64/
cp -r lib/x64/mingw/irrklang-proxy-release.dll tests/x64/
cp -r $IRRKLANG_ROOT/../x64/bin/winx64-visualStudio/ikpFlac.dll tests/x64/
cp -r $IRRKLANG_ROOT/../x64/bin/winx64-visualStudio/ikpMP3.dll tests/x64/
cp -r $IRRKLANG_ROOT/../x64/bin/winx64-visualStudio/irrKlang.dll tests/x64/

