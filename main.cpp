#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <cstdlib>
#include <cstring>

int main() {
    Display* display = XOpenDisplay(nullptr);
    if (!display) {
        return 1;
    }

    int screen = DefaultScreen(display);

    Window window = XCreateSimpleWindow(
        display,
        RootWindow(display, screen),
        100, 100,       // x, y
        800, 600,       // width, height
        2,              // border width
        BlackPixel(display, screen),
        WhitePixel(display, screen)
    );

    XStoreName(display, window, "Chess");

    XSelectInput(display, window, ExposureMask | KeyPressMask | ButtonPressMask);

    XMapWindow(display, window);

    // Atom для обработки закрытия окна
    Atom wmDelete = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window, &wmDelete, 1);

    GC gc = XCreateGC(display, window, 0, nullptr);
    XSetForeground(display, gc, BlackPixel(display, screen));

    bool running = true;
    XEvent event;

    while (running) {
        XNextEvent(display, &event);

        switch (event.type) {
            case Expose: {
                // Рисуем шахматную доску
                int cell = 70;
                for (int row = 0; row < 8; row++) {
                    for (int col = 0; col < 8; col++) {
                        bool white = (row + col) % 2 == 0;
                        XSetForeground(display, gc,
                            white ? WhitePixel(display, screen)
                                  : BlackPixel(display, screen));
                        XFillRectangle(display, window, gc,
                            50 + col * cell,
                            50 + row * cell,
                            cell, cell);
                    }
                }
                break;
            }

            case KeyPress: {
                KeySym key = XLookupKeysym(&event.xkey, 0);
                if (key == XK_Escape || key == XK_q) {
                    running = false;
                }
                break;
            }

            case ClientMessage: {
                if ((Atom)event.xclient.data.l[0] == wmDelete) {
                    running = false;
                }
                break;
            }
        }
    }

    XFreeGC(display, gc);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    return 0;
}
