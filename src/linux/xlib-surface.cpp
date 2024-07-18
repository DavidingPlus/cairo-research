#include <iostream>
#include <exception>

#include <X11/Xlib.h>

#include "cairo.h"
#include "cairo/cairo-xlib.h"


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

    XMapWindow(dpy, w);

    std::cout << "Entering loop ..." << std::endl;

    XWindowAttributes attr;
    XGetWindowAttributes(dpy, w, &attr);

    cairo_surface_t *surface = cairo_xlib_surface_create(dpy, w, attr.visual, attr.width, attr.height);
    cairo_t *cr = cairo_create(surface);

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
