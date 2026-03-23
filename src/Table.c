#include "Table.h"

Table *tableCreate(Vec2 position, float cellSize) {
  Table *table = malloc(sizeof(Table));
  table->position = position;
  table->cellSize = cellSize;
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      Vec2 position = vec2_add(table->position, (Vec2){ col * cellSize, row * cellSize });
      float size = cellSize;
      CellType type = (row + col) % 2 == 0 ? WHITE : BLACK;
      table->cells[row][col] = cellCreate(position, size, type, NULL);
    }
  }
  return table;
}

void tableFill(Table *table, char position[8][8]) {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      char c = position[row][col];
      if (c == ' ') continue;
      Vec2 pos = table->cells[row][col]->position;
      int size = (int)table->cellSize;
      table->cells[row][col]->queen = queenCreate(pos, size);
    }
  }
}

Cell *tableGetCell(Table *table, Vec2 mousePos) {
  int col = (int)(vec2_sub(mousePos, table->position).x / table->cellSize);
  int row = (int)(vec2_sub(mousePos, table->position).y / table->cellSize);
  if (col >= 0 && col < 8 && row >= 0 && row < 8) {
    return table->cells[row][col];
  }
  return NULL;
}

void tableDraw(Renderer *renderer, Table *table) {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      cellDraw(renderer, table->cells[row][col]);
    }
  }
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      if (table->cells[row][col]->queen)
        queenDraw(renderer, table->cells[row][col]->queen);
    }
  }
}

Queen *tableGetQueen(Table *table, Vec2 mousePos) {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      Queen *queen = table->cells[row][col]->queen;
      if (!queen) continue;
      if (mousePos.x >= queen->position.x &&
        mousePos.x <= queen->position.x + queen->size &&
        mousePos.y >= queen->position.y &&
        mousePos.y <= queen->position.y + queen->size) {
        return queen;
      }
    }
  }
  return NULL;
}

Cell *tableGetCellByQueen(Table *table, Queen *queen) {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      if (table->cells[row][col]->queen == queen) {
        return table->cells[row][col];
      }
    }
  }
  return NULL;
}

void tableCheckRules(Table *table) {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      Cell *cell = table->cells[row][col];
      cell->dangered = 0;
      if (cell->queen) {
        Array *damageCells = queenGetDamageCells(cell->queen, table);
        for (int i = 0; i < damageCells->size; i++) {
          IntPair pair = damageCells->data[i];
          if (table->cells[pair.a][pair.b]->queen) {
            table->cells[pair.a][pair.b]->dangered = 1; 
          } else {
            table->cells[pair.a][pair.b]->dangered = 0; 
          }
        }
        arrayFree(damageCells);
      }
    }
  }
}

void tableCellSetQueen(Table *table, Cell *cell, Queen *queen) {
  Cell *oldCell = tableGetCellByQueen(table, queen);
  if (cell->queen == NULL) {
    cellSetQueen(cell, queen);
    cellClear(oldCell);
    tableCheckRules(table);
  } else {
    cellSetQueen(oldCell, queen);
  }
}
