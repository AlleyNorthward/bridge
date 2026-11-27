#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  scanf("%d", &n);
  int* arr = malloc(sizeof(int) * n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &arr[i]);
  }

  if(n == 1){
    printf("%d", arr[0]);
    return 0;
  }

  int fast = 1, slow = 0;
  for(; fast < n-1; ++fast){
    if(!(arr[fast] < arr[fast-1] && arr[fast] < arr[fast+1])){
      arr[++slow] = arr[fast];
    }
  }

  arr[++slow] = arr[n-1];

  for(int i = 0; i < slow+1; ++i){
    if(i > 0) printf(" ");
    printf("%d", arr[i]);
  }

  free(arr);
  return 0;
}
