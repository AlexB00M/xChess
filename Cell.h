#pragma once

#include <stdlib.h>

#include "Vec2.h"
#include "Queen.h"
#include "Renderer.h"

typedef enum {
  WHITE,
  BLACK
} CellType;

typedef struct Cell
{ 
  Queen *queen;
  Vec2 position;
  CellType type;
  float size;
  int dangered;
} Cell;

Cell *cellCreate(Vec2 position, float size, CellType type, Queen *queen);

void cellSetQueen(Cell *cell, Queen *queen);

void cellDraw(Renderer *renderer, Cell *cell);
void cellClear(Cell *cell);
void cellFree(Cell *cell);
