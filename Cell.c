#include "./Cell.h"


Cell *cellCreate(Vec2 position, float size, Queen *queen) {
  Cell *cell = malloc(sizeof(Cell));
  cell->position = position;
  cell->size = size;
  cell->queen = queen;
  return cell;
}

void cellSetQueen(Cell *cell, Queen *queen) {
  if (cell->queen != NULL) {
    cell->queen = queen;
  }
}

void drawCell(Cell *cell) {

}
