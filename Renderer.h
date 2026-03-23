#pragma once

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <stdlib.h>

typedef struct Renderer {
  Display *display;
  Window window;
  GC gc;
  Atom wmDelete;
  int screen;
  unsigned long colorGreen;
  unsigned long colorRed;
} Renderer;

Renderer *rendererCreate(const char *windowTitle, int width, int height);
void rendererDestroy(Renderer *renderer);
