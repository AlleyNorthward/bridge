#include <stdio.h>
#include <stdlib.h>

int isinslow(int* arr, int slow, int x){
  for(int i = 0; i < slow; ++i){
    if(arr[i] == x)
      return 1;
  }
  return 0;
}

int main(){
  int n;
  scanf("%d", &n);
  int* arr = malloc(sizeof(int) * n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &arr[i]);
  }

  int fast = 0, slow = 0;
  for(; fast < n; ++fast){
    if(!isinslow(arr, slow, arr[fast])){
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
