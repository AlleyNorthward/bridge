#include <stdio.h>
#include <stdlib.h>

void reverse(int *arr, int left, int right) {
  if (right <= left)
    return;

  while (left < right) {
    int tmp = arr[left];
    arr[left++] = arr[right];
    arr[right--] = tmp;
  }
}

int main() {
  int size, k;
  scanf("%d%d", &size, &k);
  k = k % size;

  int *arr = malloc(sizeof(int) * size);
  for (int i = 0; i < size; ++i) {
    scanf("%d", &arr[i]);
  }

  if (k != 0) {
    reverse(arr, 0, size - 1);
    reverse(arr, 0, (size - k - 1));
    reverse(arr, (size - k), size - 1);
  }

  for (int i = 0; i < size - 1; ++i)
    printf("%d ", arr[i]);

  printf("%d", arr[size - 1]);
  free(arr);
  return 0;
}
