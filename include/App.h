#pragma once

#include <string.h>
#include <stdlib.h>

#include "Renderer.h"
#include "Event.h"
#include "Table.h"

typedef struct AppInitParams {
  int cellSize;
} AppInitParams;

typedef struct App
{
  int running;
  Renderer *renderer;
  AppInitParams *initParams;
  Table *table;
  Queen *handledQueen;
} App;

App *appCreate(int argc, char *argv[], const char *windowTitle);

void appLoopStart(App *app);
void appLoopEnd(App *app);
void appClose(App *app);
