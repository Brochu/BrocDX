#include <stdio.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "brocdx.h"

#define WIDTH 1152
#define HEIGHT 864

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    if (!AllocConsole()) {
        return 1;
    }
    FILE *empty;
    freopen_s(&empty, "CONIN$", "r", stdin);
    freopen_s(&empty, "CONOUT$", "w", stdout);
    freopen_s(&empty, "CONOUT$", "w", stderr);

    printf("[APP] Starting application\n");
    bdx_start(hInstance, nShowCmd, WIDTH, HEIGHT, "BrocDX - Sample App");

    printf("[APP] Running logic here\n");
    while (bdx_win_running()) {
        // Logic here
        bool ldown = bdx_mbutton_down(MBUTTON::MBUTTON_LEFT);
        bool rdown = bdx_mbutton_down(MBUTTON::MBUTTON_RIGHT);
        bool mdown = bdx_mbutton_down(MBUTTON::MBUTTON_MIDDLE);
        printf("[APP] Mouse States:\nleft: %i\nright: %i\nmiddle: %i\n",
           (ldown) ? 1 : 0,
           (rdown) ? 1 : 0,
           (mdown) ? 1 : 0
       );
    }

    bdx_stop();
    printf("[APP] Stopping application\n");

    FreeConsole();
    return 0;
}
