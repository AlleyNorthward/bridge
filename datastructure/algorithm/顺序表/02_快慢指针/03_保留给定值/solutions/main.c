#include <stdio.h>
#include <stdlib.h>

int main(){
  int n, x;
  scanf("%d%d", &n, &x);
  int* arr = malloc(sizeof(int) * n);

  for(int i = 0; i < n; ++i){
    scanf("%d", &arr[i]);
  }

  int fast = 0, slow = 0;
  for(; fast < n; ++fast){
    if(arr[fast] == x){
      arr[slow++] = arr[fast];
    }
  }

  for(int i = 0; i < slow; ++i){
    if(i > 0) printf(" ");
    printf("%d", arr[i]);
  }

  free(arr);
  return 0;
}
