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
  int q;
  scanf("%d", &q);
  int* h = malloc(sizeof(int) * N);
  memset(h, 0x3f, sizeof(int)*N);

  while(q--){
    int c, x;
    scanf("%d%d", &c, &x);
    switch (c) {
      case 1:
        insert(h, x);
        break;
      case 2:
        printf("%d\n", contains(h, x));
        break;
    }
  }

  free(h);
  return 0;
}
