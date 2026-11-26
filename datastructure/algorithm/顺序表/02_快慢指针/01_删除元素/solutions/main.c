#include <stdio.h>
#include <stdlib.h>

void solve(int* arr, int* size, int x){
  if(size < 0)
    return;

  int  fast = 0, slow =  0;
  int n = *size;

  for(; fast < n; ++fast){
    if(arr[fast] != x){
      arr[slow++] = arr[fast];
    }
  }

  *size = slow;
}

int main(){
  int size, x;
  scanf("%d%d", &size, &x);

  int* arr = malloc(sizeof(int)*size);

  for(int i = 0; i < size; ++i)
    scanf("%d", &arr[i]);

  solve(arr, &size, x);

  for(int i = 0; i < size-1; ++i){
    printf("%d ", arr[i]);
  }

  printf("%d", arr[size-1]);
  free(arr);
  return 0;
}
