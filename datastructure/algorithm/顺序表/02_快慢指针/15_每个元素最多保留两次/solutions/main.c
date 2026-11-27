#include <stdio.h>
#include <stdlib.h>

#define N 2000003
#define EMPTY 0x3f3f3f3f

typedef struct hash_node {
  int val;
  int cnt;
} hash_node;

int find(hash_node *h, int x) {
  int k = (x % N + N) % N;
  while (h[k].val != EMPTY && h[k].val != x) {
    if (++k == N)
      k = 0;
  }

  return k;
}

int main() {
  int n;
  scanf("%d", &n);

  int *arr = malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  hash_node *h = malloc(sizeof(hash_node) * N);
  for (int i = 0; i < N; ++i) {
    h[i].val = EMPTY;
    h[i].cnt = 0;
  }

  int fast = 0, slow = 0;
  for (; fast < n; ++fast) {
    int k = find(h, arr[fast]);
    if (h[k].cnt < 2) {
      h[k].val = arr[fast];
      arr[slow++] = arr[fast];
      ++h[k].cnt;
    }
  }

  for (int i = 0; i < slow; ++i) {
    if (i > 0)
      printf(" ");
    printf("%d", arr[i]);
  }

  free(h);
  free(arr);
  return 0;
}
