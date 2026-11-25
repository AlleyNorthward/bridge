#include "./include/c/vector.h"
#include <stdio.h>
#include <stdlib.h>

void solve(vector *vec) {
  int target = 5;
  int slow = 0, fast = 0;
  int sum = 0;
  int max = 0;

  for (; fast < vec->size; ++fast) {
    sum += vec->data[fast];

    while (sum > target) {
      sum -= vec->data[slow++];
    }

    int len = fast - slow + 1;

    if (len > max)
      max = len;
  }

  printf("%d\n", max);
}

int main() {
  unsigned seed = 2234;
  int n = 5;
  srand(seed);

  vector *vec1 = newvector(100, 18, n, normalvector);
  printvector(vec1);
  solve(vec1);
  printvector(vec1);
  destroyvector(vec1);
  return 0;
}
