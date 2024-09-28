@echo off

cl -nologo -c -std:c++14 broccore.cpp
lib -nologo broccore.obj -out:brocdx.lib
