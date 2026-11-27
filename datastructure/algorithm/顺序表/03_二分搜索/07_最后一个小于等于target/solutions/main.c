#include <stdio.h>
#include <stdlib.h>

int search(int *arr, int size, int target) {
  if (size <= 0)
    return -1;

  int left = 0, right = size - 1;
  int pos = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] > target) {
      right = mid - 1;
    } else {
      pos = mid;
      left = mid + 1;
    }
  }

  return pos;
}

int main() {
  int n, target;
  scanf("%d%d", &n, &target);
  int *arr = malloc(sizeof(int) * n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  printf("%d", search(arr, n, target));

  free(arr);
  return 0;
}
