#include <iostream>
#include <exception>

#include <X11/Xlib.h>

#include "cairo.h"


int main()
{
    Display *dpy = XOpenDisplay(nullptr);
    if (!dpy)
    {
        throw std::runtime_error("Failed to open X display");
    }

    int screen = DefaultScreen(dpy);
    Window w = XCreateSimpleWindow(
        dpy,
        RootWindow(dpy, DefaultScreen(dpy)),
        100, 100, 640, 480, 0,
        BlackPixel(dpy, screen),
        BlackPixel(dpy, screen));
    XSelectInput(dpy, w, ExposureMask);

    unsigned long mask = 0;
    XGCValues values;
    GC gc = XCreateGC(dpy, w, mask, &values);

    XMapWindow(dpy, w);

    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 640, 480);
    cairo_t *cr = cairo_create(surface);

    unsigned char *pData = cairo_image_surface_get_data(surface);
    XImage *pBackBuffer = XCreateImage(
        dpy,
        DefaultVisual(dpy, screen),
        DefaultDepth(dpy, screen),
        ZPixmap,
        0,
        (char *)pData,
        640, 480,
        8,
        0);

    std::cout << "Entering loop ..." << std::endl;

    XEvent e;
    while (true)
    {
        XNextEvent(dpy, &e);

        switch (e.type)
        {
            case Expose:
            {
                std::cout << "event: Expose" << std::endl;

                cairo_set_source_rgb(cr, 1.0, 1.0, 0.5);
                cairo_paint(cr);

                cairo_set_source_rgb(cr, 1.0, 0.0, 1.0);
                cairo_move_to(cr, 100, 100);
                cairo_line_to(cr, 200, 200);
                cairo_stroke(cr);

                cairo_surface_flush(surface);

                XPutImage(
                    dpy,
                    w,
                    gc,
                    pBackBuffer,
                    0, 0,
                    0, 0,
                    640, 480);

                break;
            }
            default:
                std::cout << "event: " << e.type << std::endl;
                break;
        }
    }


    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    XDestroyWindow(dpy, w);
    XCloseDisplay(dpy);


    return 0;
}
