@echo off

cl -nologo -MT -std:c++14 main.cpp -link brocdx.lib -out:app.exe
del main.obj
