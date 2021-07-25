g++ -m32 -g -O0 "-I$IRRKLANG_ROOT/../x32/include" -c -o build/irrklang-proxy-debug.o src/dllmain.cpp
ar rcs lib/x32/linux/libirrklang-proxy-debug.a build/irrklang-proxy-debug.o
g++ -m32 -O2 "-I$IRRKLANG_ROOT/../x32/include" -c -o build/irrklang-proxy-release.o src/dllmain.cpp
ar rcs lib/x32/linux/libirrklang-proxy-release.a build/irrklang-proxy-release.o
g++ -march=x86-64 -g -O0 "-I$IRRKLANG_ROOT/../x32/include" -c -o build/irrklang-proxy-debug.o src/dllmain.cpp
ar rcs lib/x64/linux/libirrklang-proxy-debug.a build/irrklang-proxy-debug.o
g++ -march=x86-64 "-I$IRRKLANG_ROOT/../x32/include" -c -o build/irrklang-proxy-release.o src/dllmain.cpp
ar rcs lib/x64/linux/libirrklang-proxy-release.a build/irrklang-proxy-release.o