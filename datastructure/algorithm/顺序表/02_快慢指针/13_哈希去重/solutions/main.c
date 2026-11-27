#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2000003
#define EMPTY 0x3f3f3f3f

int find(int *h, int x) {
  int k = (x % N + N) % N;
  while (h[k] != EMPTY && h[k] != x) {
    if (++k == N)
      k = 0;
  }

  return k;
}

void insert(int *h, int x) { h[find(h, x)] = x; }

int contains(int *h, int x) { return h[find(h, x)] != EMPTY; }

int main() {
  int n;
  scanf("%d", &n);
  int *arr = malloc(sizeof(int) * n);
  int *h = malloc(sizeof(int) * N);
  memset(h, 0x3f, N * sizeof(int));
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  int fast = 0, slow = 0;
  for (; fast < n; ++fast) {
    if (!contains(h, arr[fast])) {
      arr[slow++] = arr[fast];
      insert(h, arr[fast]);
    }
  }

  for (int i = 0; i < slow; ++i) {
    if (i > 0)
      printf(" ");
    printf("%d", arr[i]);
  }

  free(h);
  return 0;
}
