#pragma once
#include <stdlib.h>

typedef struct {
  int a, b;
} IntPair;

typedef struct {
  IntPair *data;
  int size;
  int capacity;
} Array;

Array *arrayCreate();
void arrayPush(Array *arr, int a, int b);
void arrayClear(Array *arr);
void arrayFree(Array *arr);
