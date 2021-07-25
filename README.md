# irrklang-proxy
IrrKlang C API proxy library for linking with MinGW GCC x64.
It's a quick and dirty solution for using irrKlang with MSVC x32/x64, MinGW32/64, GCC x32/64 on Linux.

## Why?

You see, there is an issue with the irrKlang library - you can't directly link against it, using MinGW-x64. Because there are no builds for it, and the corresponding question in Ambierra's forum is at least 8 years old and still not answered.
However, using gendef and dlltool you can link to the MSVC library in MinGW and link against it if it uses C API. So, this library allows you to use irrKlang API via this C API, because
on MinGW-x64 it creates its own libraries, which calls in chain MSVC dll and then irrKlang dll

## But this means, that I'll require MSVC CRT2017 (for built library) to be present on the target machine

Yes, that's a big drawback, but it's a small price to pay for this task. If somebody got his hands on irrKlang source code, he may be tried to make a direct build and this library never happened.

## How to build it.

irrklang-proxy comes with already pre-built libraries for MSVC2017, MinGW with GCC 10.3 and, Ubuntu 21.04 GCC 11
But you can build it, starting with putting x32 and x64 irrKlang into folder structure like C:\Projects\irrKlang\x32, C:\Projects\irrKlang\x64 and setting environment variable IRRKLANG_ROOT=C:\Projects\irrKlang\x32.

Then for MSVC, you should use irrkang-proxy.sln and tests/tests.sln for building the MSVC part of the library (This is also required for MinGW-x64 build since it relies on the result of this build!).
Use build-mingw-x32.bat, build-mingw-x64.sh (build-tests-mingw-x32.bat, build-tests-mingw-x64.sh  for tests) for building with MinGW
Use build-linux.sh (build-tests-linux.sh for tests) for building on Linux (Requires g++-multilib, gcc-multilib packages for Ubuntu to build x32 versions)

## How to use it.

Instead of raw irrKlang API, you should use API, provided by the library. It's self-explanatory and the source code is there to help you. Underneath all it does is calls corresponding irrKlang functions. For callbacks and inherited classes, I recommend using classes from the library and make_XXX::exec methods to convert it to irrKlang classes, since it partially allows to fix ABI incompatibilities between code, compiled by MSVC and MinGW. Note, that you SHOULD NOT THROW ANY EXCEPTIONS in your new classes and methods, since this is not allowed in C functions and is not standardized. You've been warned. However, if you catch exceptions inside your class and handle them, you're free to go.
