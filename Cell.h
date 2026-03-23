#pragma once

#include <stdlib.h>

#include "Vec2.h"
#include "Queen.h"

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
} Cell;

Cell *cellCreate(Vec2 position, float size, Queen *queen);

void cellSetQueen(Cell *cell, Queen *queen);

void drawCell(Cell *cell);
