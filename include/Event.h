#pragma once
#include <X11/Xlib.h>
#include <X11/keysym.h>

typedef struct App App;

void eventHandle(App *app, XEvent event);
