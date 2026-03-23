#pragma once

#include <string.h>
#include <stdlib.h>

#include "Renderer.h"
#include "Event.h"

typedef struct App
{
  int running;
  Renderer *renderer;
} App;

App *appCreate(int argc, char *argv[], const char *windowTitle);

void appLoopStart(App *app);
void appLoopEnd(App *app);
void appClose(App *app);
