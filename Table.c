#include "Table.h"

Table *tableCreate(Vec2 position, float cellSize) {
  Table *table = malloc(sizeof(Table));
  table->position = position;
  table->cellSize = cellSize;
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      Vec2 position = vec2_add(table->position, (Vec2){ col * cellSize, row * cellSize });
      float size = cellSize;
      table->cells[row][col] = cellCreate(position, size, NULL);
    }
  }
  return table;
}

Cell *getCell(Table *table, Vec2 mousePos) {
  int col = (int)(vec2_sub(mousePos, table->position).x / table->cellSize);
  int row = (int)(vec2_sub(mousePos, table->position).y / table->cellSize);
  if (col >= 0 && col < 8 && row >= 0 && row < 8) {
    return table->cells[row][col];
  }
  return NULL;
}

void drawTable(Table *table) {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      drawCell(table->cells[row][col]);
    }
  }
}
