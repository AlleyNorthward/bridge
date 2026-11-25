#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void sortvector(vector *v, int order) {
  if (!v || !v->data || v->size <= 1)
    return;
  size_t i, j, idx;
  for (i = 0; i < v->size - 1; i++) {
    idx = i;
    for (j = i + 1; j < v->size; j++) {
      if ((order == 0 && v->data[j] < v->data[idx]) ||
          (order == 1 && v->data[j] > v->data[idx])) {
        idx = j;
      }
    }
    int tmp = v->data[i];
    v->data[i] = v->data[idx];
    v->data[idx] = tmp;
  }
}

void normalvector(vector *vec, int n) {
  for (size_t i = 0; i < vec->size; ++i) {
    vec->data[i] = -n + rand() % (2 * n + 1);
  }
}

void uniquevector(vector *vec, int n) {
  size_t k = vec->size;
  int L = -n;
  int R = n;
  int total = R - L + 1;
  if (k > (size_t)total)
    return;

  vec->size = 0;
  for (int x = L; x <= R; x++) {
    vec->data[vec->size++] = x;
  }
  for (size_t i = vec->size - 1; i > 0; i--) {
    size_t r = rand() % (i + 1);
    int tmp = vec->data[i];
    vec->data[i] = vec->data[r];
    vec->data[r] = tmp;
  }
  vec->size = k;
}

vector *newvector(size_t capacity, size_t size, int n,
                  void (*init)(vector *vec, int n)) {
  vector *vec = malloc(sizeof(vector));
  vec->data = malloc(capacity * sizeof(int));
  vec->size = size;
  vec->capacity = capacity;
  init(vec, n);
  return vec;
}

void destroyvector(vector *vec) {
  free(vec->data);
  free(vec);
}

void printvector(vector *vec) {
  for (int i = 0; i < vec->size; ++i) {
    printf("%d ", vec->data[i]);
  }
  putchar('\n');
}
