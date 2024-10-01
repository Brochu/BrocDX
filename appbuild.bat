@echo off

:: Necessary external libs for brocdx to resolve everything:
:: - dxgi.lib
:: - d3d12.lib

cl -nologo -MT -std:c++14 main.cpp -link user32.lib dxgi.lib d3d12.lib brocdx.lib -out:app.exe
del main.obj
