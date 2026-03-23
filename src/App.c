#include "App.h"

AppInitParams *AppInitParamsParse(int argc, char *argv[]);

App *appCreate(int argc, char *argv[], const char *windowTitle){
  App *app = (App *)malloc(sizeof(App));
  app->running = 1;
  app->initParams = AppInitParamsParse(argc, argv);
  app->table = tableCreate((Vec2){0, 0}, app->initParams->cellSize);
  app->renderer = rendererCreate(windowTitle, app->table->cellSize * 8, app->table->cellSize * 8);
  app->handledQueen = NULL;
  if (!app->renderer) {
    free(app);
    return NULL;
  }
  return app;
}

void appLoopStart(App *app) {
  XEvent event;
  while (app->running) {
    XNextEvent(app->renderer->display, &event);
    eventHandle(app, event);
    tableDraw(app->renderer, app->table);
  }
}

void appLoopEnd(App *app) {
  app->running = 0;
}

void appClose(App *app) {
  rendererDestroy(app->renderer);
  free(app);
}

AppInitParams *AppInitParamsParse(int argc, char *argv[]) {
  AppInitParams *params = (AppInitParams *)malloc(sizeof(AppInitParams));
  params->cellSize = 80; 
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "--cell-size") == 0 && i + 1 < argc) {
      params->cellSize = atoi(argv[i + 1]);
      i++; 
    }
  }
  return params;
}
