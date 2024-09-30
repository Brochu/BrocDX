@echo off

cl -nologo -c -std:c++14 bdxcore.cpp bdxwin.cpp
lib -nologo bdxcore.obj bdxwin.obj -out:brocdx.lib
del bdxcore.obj
del bdxwin.obj
