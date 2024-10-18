#ifndef BROCDX_H
#define BROCDX_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

typedef enum {
    MBUTTON_LEFT,
    MBUTTON_RIGHT,
    MBUTTON_MIDDLE,
} MBUTTON;

void bdx_start(HINSTANCE hInstance, int nShowCmd, int width, int height, const char *title);
void bdx_stop();

bool bdx_win_running();

bool bdx_mbutton_down(MBUTTON button);

#endif //BROCDX_H
