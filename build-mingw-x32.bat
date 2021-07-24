g++ -g -O0 -I"%IRRKLANG_ROOT%/../x32/include" -c -o build/irrklang-proxy-debug.o src/dllmain.cpp
ar rcs lib/x32/mingw/libirrklang-proxy-debug.a build/irrklang-proxy-debug.o
g++ -O2 -I"%IRRKLANG_ROOT%/../x32/include" -c -o build/irrklang-proxy-release.o src/dllmain.cpp
ar rcs lib/x32/mingw/libirrklang-proxy-release.a build/irrklang-proxy-release.o
