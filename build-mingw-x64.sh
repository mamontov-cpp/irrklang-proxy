./bin/gendef lib/x64/msvc/irrklang-proxy-debug.dll
mv -f irrklang-proxy-debug.def lib/x64/mingw/irrklang-proxy-debug.def
cp -r lib/x64/msvc/irrklang-proxy-debug.dll lib/x64/mingw/irrklang-proxy-debug.dll
dlltool -v -d lib/x64/mingw/irrklang-proxy-debug.def -l lib/x64/mingw/libirrklang-proxy-debug.a
./bin/gendef lib/x64/msvc/irrklang-proxy-release.dll
mv -f irrklang-proxy-release.def lib/x64/mingw/irrklang-proxy-release.def
cp -r lib/x64/msvc/irrklang-proxy-release.dll lib/x64/mingw/irrklang-proxy-release.dll
dlltool -v -d lib/x64/mingw/irrklang-proxy-release.def -l lib/x64/mingw/libirrklang-proxy-release.a