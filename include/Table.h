#pragma once

#include "Cell.h"
#include "Vec2.h"
#include "Renderer.h"
#include "Queen.h"

typedef struct Table {
  Vec2 position;
  float cellSize;
  Cell *cells[8][8];
} Table;

Table *tableCreate(Vec2 position, float cellSize);

Cell *tableGetCell(Table *table, Vec2 mousePos);
Queen *tableGetQueen(Table *table, Vec2 mousePos);
Cell *tableGetCellByQueen(Table *table, Queen *queen);

void tableDraw(Renderer *renderer, Table *table);
void tableCellSetQueen(Table *table, Cell *cell, Queen *queen);
void tableFill(Table *table, char possition[8][8]);
void tableCheckRules(Table *table);