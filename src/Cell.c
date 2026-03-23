#include "Cell.h"

Cell *cellCreate(Vec2 position, float size, CellType type, Queen *queen) {
  Cell *cell = malloc(sizeof(Cell));
  cell->position = position;
  cell->size = size;
  cell->type = type;
  cell->queen = NULL;
  cell->dangered = 0;
  if (queen != NULL) {
    cellSetQueen(cell, queen);
  }
  return cell;
}

void cellSetQueen(Cell *cell, Queen *queen) {
  cell->queen = queen;
  if (queen != NULL) {
    queen->position = cell->position;
    queen->size = (int)cell->size;
  }
}

void cellDraw(Renderer *renderer, Cell *cell) {
  unsigned long color;
  if (cell->dangered)
    color = renderer->colorRed;
  else
    color = cell->type == WHITE ? WhitePixel(renderer->display, renderer->screen) : BlackPixel(renderer->display, renderer->screen);
  XSetForeground(renderer->display, renderer->gc, color);
  XFillRectangle(renderer->display, renderer->window, renderer->gc, cell->position.x, cell->position.y, cell->size, cell->size);
  XSetForeground(renderer->display, renderer->gc, BlackPixel(renderer->display, renderer->screen));
  XDrawRectangle(renderer->display, renderer->window, renderer->gc, cell->position.x, cell->position.y, cell->size, cell->size);
}

void cellClear(Cell *cell){
  cell->queen = NULL;
  cell->dangered = 0;
}

void cellFree(Cell *cell) {
  free(cell);
}
