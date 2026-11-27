#include <stdio.h>
#include <stdlib.h>

int main(){
  int n, x;
  scanf("%d%d", &n, &x);
  int * arr = malloc(sizeof(int) * n);
  for(int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
  int fast = 0, slow = 0;

  int size = n;
  while(fast < size){
    if(arr[fast] < x){
      int tmp = arr[slow];
      arr[slow++] = arr[fast];
      arr[fast++] = tmp;
    }
    else if(arr[fast] > x){
      int tmp = arr[fast];
      arr[fast] = arr[size-1];
      arr[size-1] = tmp;
      --size;
    }
    else{
      ++fast;
    }
  }

  for(int i =0; i < n; ++i){
    if(i > 0) printf(" ");
    printf("%d", arr[i]);
  }

  free(arr);
  return 0;
}
