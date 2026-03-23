#pragma once
#include "Vec2.h"

typedef struct Queen {
    Vec2 position;
} Queen;

Queen *queenCreate(Vec2 position);

void queenMoveTo(Queen *self, Vec2 target);

