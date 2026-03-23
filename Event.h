#pragma once
#include <X11/Xutil.h>

#include "Event.h"
#include "App.h"

void eventHandle(App *app, XEvent event);
