#include "Queen.h"

Queen *queenCreate(Vec2 position) {
  Queen *queen = malloc(sizeof(Queen));
  queen->position = position;
  return queen;
}

void queenMoveTo(Queen *self, Vec2 target) {
    self->position = target;
}
