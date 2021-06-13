./gendef irrklang-proxy-debug.dll
dlltool -v -d irrklang-proxy-debug.def -l libirrklang-proxy-debug.a
./gendef irrklang-proxy-release.dll
dlltool -v -d irrklang-proxy-release.def -l libirrklang-proxy-release.a