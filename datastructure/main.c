#include <stdlib.h>
#include <stdio.h>

int search(int* arr, int size, int target){
  if(size <= 0)
    return 0;

  int left = 0, right = size - 1;
  while(left <= right){
    int mid = left + (right - left ) / 2;

    if(arr[mid] < target){
      left = mid + 1;
    } else if(arr[mid] > target){
      right = mid - 1;
    } else {
      return 1;
    }
  }

  return 0;
}

int main(){
  int n, target;
  scanf("%d%d", &n, &target);
  int* arr = malloc(sizeof(int) * n);
  printf("%d", search(arr, n, target));
  free(arr);

  return 0;
}
