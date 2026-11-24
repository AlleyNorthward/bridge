#include "vector.h"
#include <stdlib.h>
#include <stdio.h>


void solve(vector *vec) {
  int target = 2;
  int start = 0, end = vec->size - 1;
  int pos = -1;
  while(start<=end){
    int mid = start + (end - start) / 2;
    if(vec->data[mid] < target){
      start = mid+1;
    } else if(vec->data[mid] > target){
      end = mid-1;
    } else {
      pos = mid;
      end = mid-1;
    }
  }

  printf("pos: %d\n", pos);

}

int main() {
  unsigned seed = 2234;
  int n = 3;
  srand(seed);

  vector *vec1 = newvector(100, 24, n, normalvector);
  sortvector(vec1, 0);
  printvector(vec1);
  solve(vec1);
  printvector(vec1);
  destroyvector(vec1);
  return 0;
}
