#pragma once

#include "Cell.h"
#include "Vec2.h"

typedef struct Table {
  Vec2 position;
  float cellSize;
  Cell *cells[8][8];
} Table;

Table *tableCreate(Vec2 position, float cellSize);

Cell *getCell(Table *table, Vec2 mousePos);

void  drawTable(Table *table);
