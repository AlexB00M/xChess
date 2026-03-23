#include "Queen.h"
#include "Table.h"

Queen *queenCreate(Vec2 position, int size) {
  Queen *queen = malloc(sizeof(Queen));
  queen->position = position;
  queen->size = size;
  queen->handled = 0;
  return queen;
}

void queenMoveTo(Queen *self, Vec2 target) {
  self->position = target;
}

void queenDraw(Renderer *renderer, Queen *queen){
  XSetForeground(renderer->display, renderer->gc, renderer->colorGreen);
  XFillArc(renderer->display, renderer->window, renderer->gc, queen->position.x, queen->position.y, queen->size, queen->size, 0, 360 * 64);
}

Array *queenGetDamageCells(Queen *queen, Table *table) {
  Array *damageCells = arrayCreate();
  int queenRow = (int)(queen->position.y / table->cellSize);
  int queenCol = (int)(queen->position.x / table->cellSize);

  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      if (row == queenRow && col == queenCol) continue;
      if (row == queenRow || col == queenCol ||
          abs(row - queenRow) == abs(col - queenCol)) {
        arrayPush(damageCells, row, col);
      }
    }
  }
  
  return damageCells;
}
 