#include <stdio.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "brocdx.h"

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    if (!AllocConsole()) {
        return 1;
    }
    FILE *empty;
    freopen_s(&empty, "CONIN$", "r", stdin);
    freopen_s(&empty, "CONOUT$", "w", stdout);
    freopen_s(&empty, "CONOUT$", "w", stderr);

    printf("[APP] Starting application\n");
    bdx_start(hInstance, nShowCmd);

    printf("[APP] Running logic here\n");

    bdx_stop();
    printf("[APP] Stopping application\n");

    FreeConsole();
    return 0;
}
