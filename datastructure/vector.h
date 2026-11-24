#ifndef VECTOR_H
#include <stddef.h>
typedef struct vector {
  int *data;
  size_t size;
  size_t capacity;
} vector;

void sortvector(vector *v, int order);
void normalvector(vector *vec, int n);
void uniquevector(vector *vec, int n);
vector *newvector(size_t capacity, size_t size, int n,
                  void (*init)(vector *vec, int n));
void destroyvector(vector *vec);
void printvector(vector *vec);

#endif // !VECTOR_H
