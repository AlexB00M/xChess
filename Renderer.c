#include "Renderer.h"

Renderer *rendererCreate(const char *windowTitle) {
  Renderer *renderer = (Renderer *)malloc(sizeof(Renderer));
  renderer->display = XOpenDisplay(NULL);
  if (!renderer->display) {
    free(renderer);
    return NULL;
  }

  renderer->screen = DefaultScreen(renderer->display);

  renderer->window = XCreateSimpleWindow(
      renderer->display,
      RootWindow(renderer->display, renderer->screen),
      100, 100,
      800, 600,
      2,
      BlackPixel(renderer->display, renderer->screen),
      WhitePixel(renderer->display, renderer->screen)
  );

  XStoreName(renderer->display, renderer->window, windowTitle);
  XSelectInput(renderer->display, renderer->window, ExposureMask | KeyPressMask | ButtonPressMask);
  XMapWindow(renderer->display, renderer->window);

  Atom wmDelete = XInternAtom(renderer->display, "WM_DELETE_WINDOW", False);
  XSetWMProtocols(renderer->display, renderer->window, &wmDelete, 1);

  renderer->gc = XCreateGC(renderer->display, renderer->window, 0, NULL);
  XSetForeground(renderer->display, renderer->gc, BlackPixel(renderer->display, renderer->screen));

  return renderer;
}

void rendererDestroy(Renderer *renderer) {
  XFreeGC(renderer->display, renderer->gc);
  XDestroyWindow(renderer->display, renderer->window);
  XCloseDisplay(renderer->display);
  free(renderer);
}
