#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  scanf("%d", &n);
  int*arr = malloc(sizeof(int) * n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &arr[i]);
  }

  int fast = 1, slow = 0;
  for(; fast < n; ++fast){
    if(arr[fast] != arr[slow])
      arr[++slow] = arr[fast];
  }

  for(int i = 0; i < slow+1; ++i){
    if(i > 0) printf(" ");
    printf("%d", arr[i]);
  }

  free(arr);
  return 0;
}
