#ifndef BROCDX_H
#define BROCDX_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

void bdx_start(HINSTANCE hInstance, int nShowCmd);
void bdx_stop();

bool bdx_win_running();

#endif //BROCDX_H
