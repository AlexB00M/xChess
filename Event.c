#include "Event.h"

static void handleExpose(App *app, XEvent event);
static void handleKeyPress(App *app, XEvent event);
static void handleClientMessage(App *app, XEvent event);

void eventHandle(App *app, XEvent event) {
  switch (event.type) {
    case Expose: {
      handleExpose(app, event);
      break;
    }

    case KeyPress: {
      handleKeyPress(app, event);
      break;
    }

    case ClientMessage: {
      handleClientMessage(app, event);
      break;
    }
  }
}

static void handleExpose(App *app, XEvent event){
  
}
static void handleKeyPress(App *app, XEvent event){
  KeySym key = XLookupKeysym(&event.xkey, 0);
  if (key == XK_Escape || key == XK_q) {
    app->running = 0;
  }
}
static void handleClientMessage(App *app, XEvent event){
  if ((Atom)event.xclient.data.l[0] == app->renderer->wmDelete) {
    appClose(app);
  }
}
