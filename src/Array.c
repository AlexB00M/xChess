#include "Array.h"

Array *arrayCreate() {
  Array *arr = malloc(sizeof(Array));
  arr->data = NULL;
  arr->size = 0;
  arr->capacity = 0;
  return arr;
}

void arrayPush(Array *arr, int a, int b) {
  if (arr->size == arr->capacity) {
    arr->capacity = arr->capacity == 0 ? 4 : arr->capacity * 2;
    arr->data = realloc(arr->data, arr->capacity * sizeof(IntPair));
  }
  arr->data[arr->size++] = (IntPair){ a, b };
}

void arrayClear(Array *arr) {
  arr->size = 0;
}

void arrayFree(Array *arr) {
  free(arr->data);
  arr->data = NULL;
  arr->size = 0;
  arr->capacity = 0;
}
