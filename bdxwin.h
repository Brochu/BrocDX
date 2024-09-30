#ifndef BDXWIN_H
#define BDXWIN_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

extern HWND hwnd;

void bdx_init_window();
void bdx_close_window();

#endif //BDXWIN_H
