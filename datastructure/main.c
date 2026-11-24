#include "vector.h"
#include <stdlib.h>

void solve(vector *vec) {
  int fast = 1, slow = 0;
  for(;fast<vec->size;++fast){
    if(vec->data[fast] != vec->data[slow]){
      vec->data[++slow] = vec->data[fast];
    }
  }

  vec->size = slow+1;
}

int main() {
  unsigned seed = 2234;
  int n = 10;
  srand(seed);

  vector *vec1 = newvector(100, 24, n, normalvector);
  sortvector(vec1, 0);
  printvector(vec1);
  solve(vec1);
  printvector(vec1);
  destroyvector(vec1);
  return 0;
}
