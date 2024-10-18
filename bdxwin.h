#ifndef BDXWIN_H
#define BDXWIN_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

extern HWND hwnd;
extern bool running;
extern bool mouse_buttons[3];

void bdx_init_window(HINSTANCE hInstance, int nShowCmd, int width, int height, const char *title);
void bdx_close_window();

#endif //BDXWIN_H
