#pragma once

#include "Vec2.h"
#include "Renderer.h"
#include "Array.h"

typedef struct Table Table;

typedef struct Queen {
    Vec2 position;
    int size;
    int handled;
} Queen;

Queen *queenCreate(Vec2 position, int size);

void queenMoveTo(Queen *self, Vec2 target);
void queenDraw(Renderer *renderer, Queen *queen);

Array *queenGetDamageCells(Queen *queen, Table *table);

