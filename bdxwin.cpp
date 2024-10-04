#include "bdxwin.h"
#include <stdio.h>

HWND hwnd = (HWND)11;
bool running = true;

LRESULT CALLBACK window_proc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
    switch (message) {

    // TODO: Think about how to send inputs to core

    case WM_DESTROY:
    case WM_QUIT:
        running = false;
        return 0;

    }

    return DefWindowProc(hwnd, message, wparam, lparam);
}

void bdx_init_window(HINSTANCE hInstance, int nShowCmd/*, LONG width, LONG height, const char *title*/) {
    printf("[WIN] Creating Win32 window\n");
    printf("\thInstance=0x%p ; nShowCmd=%i ; hwnd = 0x%p\n", hInstance, nShowCmd, hwnd);

    WNDCLASSEX wndClass = { 0 };
    wndClass.cbSize = sizeof(WNDCLASSEX);
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = window_proc;
    wndClass.hInstance = hInstance;
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.lpszClassName = "BrocDXWindowClass";
    RegisterClassEx(&wndClass);

    RECT wrect = { 0, 0, 800, 600 };
    AdjustWindowRect(&wrect, WS_OVERLAPPEDWINDOW, FALSE);


    hwnd = CreateWindow(
        wndClass.lpszClassName, "INSERT TITILE HERE",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600, nullptr, nullptr, hInstance, nullptr
    );

    ShowWindow(hwnd, nShowCmd);
}

bool bdx_win_running() {
    MSG m = { 0 };
    while (PeekMessage(&m, NULL, 0, 0, PM_REMOVE)) {
        if (m.message == WM_QUIT) {
            return false;
        }

        TranslateMessage(&m);
        DispatchMessage(&m);
    }

    return running;
}

void bdx_close_window() {
    printf("[WIN] Closing Win32 window\n");
    DestroyWindow(hwnd);
}
