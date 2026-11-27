#include <stdio.h>
#include <stdlib.h>
void merge(int* arr, int left, int mid, int right){
  int* tmp = malloc(sizeof(int) * (right - left + 1));
  int p1 = left;
  int p2 = mid + 1;
  int p3 = 0;
  while(p1 < mid+1 && p2 < right+1){
    if(arr[p1] <= arr[p2]){
      tmp[p3++] = arr[p1++];
    } else{
      tmp[p3++] = arr[p2++];
    }
  }

  while(p1 < mid+1){
    tmp[p3++] = arr[p1++];
  }

  while(p2 < mid + 1){
    tmp[p3++] = arr[p2++];
  }

  for(int i = 0; i < p3; ++i){
    arr[left + i] = tmp[i];
  }

  free(tmp);
}
void mergeSort(int *arr, int left, int right){
  if(right <= left)
    return;

  int mid = left + (right - left) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid+1, right);
  merge(arr, left, mid, right);
}

int main(){
  int n;
  scanf("%d", &n);
  int* arr = malloc(sizeof(int) * n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &arr[i]);
  }
  mergeSort(arr, 0, n-1);
  
  int fast = 1, slow = 0;
  for(; fast < n; ++fast){
    if(arr[fast] != arr[slow]){
      arr[++slow] = arr[fast];
    }
  }

  for(int i = 0; i < slow + 1; ++i){
    if(i > 0) printf(" ");
    printf("%d", arr[i]);
  }

  free(arr);
  return 0;
}
