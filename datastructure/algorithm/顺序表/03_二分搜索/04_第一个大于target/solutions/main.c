#include <stdlib.h>
#include <stdio.h>
int search(int* arr, int size, int target){
  if(size <= 0)
    return -1;
  int left = 0, right = size - 1;
  int pos = -1;

  while(left <= right){
    int mid = left + (right - left) / 2;

    if(arr[mid] < target){
      left = mid + 1;
    } else if(arr[mid] > target){
      pos = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return pos;
}

int main(){
  int n, target;
  scanf("%d%d", &n, &target);
  int *arr = malloc(sizeof(int) * n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &arr[i]);
  }

  printf("%d", search(arr, n, target));
  free(arr);
  return 0;
}
