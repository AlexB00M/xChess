#include "Event.h"
#include "App.h"

static void handleKeyPress(App *app, XEvent event);
static void handleClientMessage(App *app, XEvent event);

static void handleMousePress(App *app, XEvent event);
static void handleMouseRelease(App *app, XEvent event);

void eventHandle(App *app, XEvent event) {
  switch (event.type) {
    case KeyPress: {
      handleKeyPress(app, event);
      break;
    }

    case ClientMessage: {
      handleClientMessage(app, event);
      break;
    }
    
    case ButtonPress: {
      if (event.xbutton.button == Button1) {
        handleMousePress(app, event);
      }
      break;
    }

    case ButtonRelease: {
      if (event.xbutton.button == Button1) {
          handleMouseRelease(app, event);
      }
      break;
    }

    case MotionNotify: {
      if (app->handledQueen) {
        app->handledQueen->position = (Vec2){ event.xmotion.x - app->handledQueen->size / 2, event.xmotion.y - app->handledQueen->size / 2 };
      }
    }
  }
}

static void handleMousePress(App *app, XEvent event){
  Vec2 mousePos = { event.xbutton.x, event.xbutton.y };
  Queen *queen = tableGetQueen(app->table, mousePos);
  if (queen) {
    app->handledQueen = queen;
  }
}

static void handleMouseRelease(App *app, XEvent event){
  if (!app->handledQueen) return;
  Vec2 mousePos = { event.xbutton.x, event.xbutton.y };
  Cell *cell = tableGetCell(app->table, mousePos);
  tableCellSetQueen(app->table, cell, app->handledQueen);
  app->handledQueen = NULL;
}

static void handleKeyPress(App *app, XEvent event){
  KeySym key = XLookupKeysym(&event.xkey, 0);
  if (key == XK_Escape || key == XK_q) {
    app->running = 0;
  }
}
static void handleClientMessage(App *app, XEvent event){
  if ((Atom)event.xclient.data.l[0] == app->renderer->wmDelete) {
    appLoopEnd(app);
  }
}
