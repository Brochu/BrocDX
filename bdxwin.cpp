#include "bdxwin.h"
#include "brocdx.h"

#include <stdio.h>

HWND hwnd = (HWND)11;
bool running = true;
bool mouse_buttons[3] = { false, false, false };

LRESULT CALLBACK window_proc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
    switch (message) {

    // TODO: Think about how to send inputs to core

    case WM_LBUTTONDOWN:
            mouse_buttons[0] = true;
        break;
    case WM_LBUTTONUP:
            mouse_buttons[0] = false;
        break;

    case WM_RBUTTONDOWN:
            mouse_buttons[1] = true;
        break;
    case WM_RBUTTONUP:
            mouse_buttons[1] = false;
        break;

    case WM_MBUTTONDOWN:
            mouse_buttons[2] = true;
        break;
    case WM_MBUTTONUP:
            mouse_buttons[2] = false;
        break;

    case WM_DESTROY:
    case WM_QUIT:
        running = false;
        return 0;

    }

    return DefWindowProc(hwnd, message, wparam, lparam);
}

void bdx_init_window(HINSTANCE hInstance, int nShowCmd, int width, int height, const char *title) {
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

    RECT wrect = { 0, 0, width, height };
    AdjustWindowRect(&wrect, WS_OVERLAPPEDWINDOW, FALSE);


    hwnd = CreateWindow(
        wndClass.lpszClassName, title,
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        width, height, nullptr, nullptr, hInstance, nullptr
    );

    ShowWindow(hwnd, nShowCmd);
}

void bdx_close_window() {
    printf("[WIN] Closing Win32 window\n");
    DestroyWindow(hwnd);
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

bool bdx_mbutton_down(MBUTTON button) {
    return mouse_buttons[button];
}
