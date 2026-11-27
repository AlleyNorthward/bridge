#include <stdio.h>
#include <stdlib.h>

#define N 2000003
#define EMPTY 0x3f3f3f3f

typedef struct hash{
  int val;
  int cnt;
  long long sum;
}hash;

int find(hash* h, int x) {
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
  hash* h = malloc(sizeof(hash) * N);
  for (int i = 0; i < N; ++i) {
    h[i].val = EMPTY;
    h[i].cnt = 0;
    h[i].sum = 0;
  }

  int *out = malloc(sizeof(int) * n);
  int out_size = 0;

  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    int k = find(h, arr[i]);
    if (h[k].val == EMPTY) {
      h[k].val = arr[i];
      h[k].cnt = 1;
      out[out_size++] = arr[i];
    } else {
      ++h[k].cnt;
    }
    h[k].sum += arr[i];
  }

  for (int i = 0; i < out_size; ++i) {
    int k = find(h, out[i]);
    printf("%d %d %lld\n", h[k].val, h[k].cnt, h[k].sum);
  }

  free(out);
  free(h);
  free(arr);
  return 0;
}
