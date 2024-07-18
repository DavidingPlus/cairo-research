#ifndef UNICODE
#define UNICODE
#endif


#include <iostream>

#include <windows.h>
#include <windowsx.h>

#include "cairo.h"
#include "cairo-win32.h"


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChildWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t wclass[] = L"Sample Window Class";
    const wchar_t wclassChild[] = L"Sample Window Class Child";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = wclass;
    RegisterClass(&wc);

    // Create the window.
    HWND hwnd = CreateWindowEx(
        0,                   // Optional window styles.
        wclass,              // Window class
        L"Hello Win32",      // Window text
        WS_OVERLAPPEDWINDOW, // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,

        NULL,      // Parent window
        NULL,      // Menu
        hInstance, // Instance handle
        NULL       // Additional application data
    );
    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    // ShowWindow(hwndChild, nCmdShow);

    // Run the message loop.
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }


    return 0;
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    cairo_surface_t *surface;
    cairo_t *cr;
    HDC hdc;
    auto xPos = GET_X_LPARAM(lParam);
    auto yPos = GET_Y_LPARAM(lParam);
    switch (uMsg)
    {
        case WM_DESTROY:
            ::SendMessage(hwnd, WM_CLOSE, 0, 0);
            PostQuitMessage(0);
            return 0;

        case WM_LBUTTONDOWN:
            hdc = GetDC(hwnd);
            std::cout << xPos << "," << yPos << std::endl;
            surface = cairo_win32_surface_create(hdc);
            cr = cairo_create(surface);


            cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);
            cairo_select_font_face(cr, "Adobe Heiti Std",
                                   CAIRO_FONT_SLANT_NORMAL,
                                   CAIRO_FONT_WEIGHT_NORMAL);
            cairo_set_font_size(cr, 8.0);

            cairo_move_to(cr, xPos, yPos);
            cairo_show_text(cr, "Hello,Cairo!");

            cairo_destroy(cr);
            cairo_surface_destroy(surface);
            break;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

            surface = cairo_win32_surface_create(hdc);
            cr = cairo_create(surface);


            cairo_set_source_rgb(cr, 0.627, 0, 0);
            cairo_select_font_face(cr, "Adobe Heiti Std",
                                   CAIRO_FONT_SLANT_NORMAL,
                                   CAIRO_FONT_WEIGHT_NORMAL);
            cairo_set_font_size(cr, 24.0);

            cairo_move_to(cr, 10.0, 34.0);
            cairo_show_text(cr, "Hello,Cairo!");

            cairo_destroy(cr);
            cairo_surface_destroy(surface);

            EndPaint(hwnd, &ps);
        }
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


LRESULT CALLBACK ChildWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    cairo_surface_t *surface;
    cairo_t *cr;
    HDC hdc;
    auto xPos = GET_X_LPARAM(lParam);
    auto yPos = GET_Y_LPARAM(lParam);
    switch (uMsg)
    {
        case WM_DESTROY:
            ::SendMessage(hwnd, WM_CLOSE, 0, 0);
            return 0;

        case WM_LBUTTONDBLCLK:
            hdc = GetDC(hwnd);

            surface = cairo_win32_surface_create(hdc);
            cr = cairo_create(surface);


            cairo_set_source_rgb(cr, 0.627, 0, 0);
            cairo_select_font_face(cr, "Adobe Heiti Std",
                                   CAIRO_FONT_SLANT_NORMAL,
                                   CAIRO_FONT_WEIGHT_NORMAL);
            cairo_set_font_size(cr, 8.0);

            cairo_move_to(cr, xPos, yPos);
            cairo_show_text(cr, "Hello,I'm child!");

            cairo_destroy(cr);
            cairo_surface_destroy(surface);
            break;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

            surface = cairo_win32_surface_create(hdc);
            cr = cairo_create(surface);


            cairo_set_source_rgb(cr, 0.627, 0, 0);
            cairo_select_font_face(cr, "Adobe Heiti Std",
                                   CAIRO_FONT_SLANT_NORMAL,
                                   CAIRO_FONT_WEIGHT_NORMAL);
            cairo_set_font_size(cr, 24.0);

            cairo_move_to(cr, 10.0, 34.0);
            cairo_show_text(cr, "Hello,I'm child!");

            cairo_destroy(cr);
            cairo_surface_destroy(surface);

            EndPaint(hwnd, &ps);
        }
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
