@echo off

cl -nologo -c -std:c++14 bdxcore.cpp
lib -nologo bdxcore.obj dxgi.lib -out:brocdx.lib
