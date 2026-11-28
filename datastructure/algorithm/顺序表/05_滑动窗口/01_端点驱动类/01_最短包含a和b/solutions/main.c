#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);

  int *arr = malloc(sizeof *arr * n);

  int firstA = -1, lastA = -1;
  int firstB = -1, lastB = -1;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);

    if (x == a) {
      if (firstA == -1)
        firstA = i;
      lastA = i;
    }

    if (x == b) {
      if (firstB == -1)
        firstB = i;
      lastB = i;
    }
  }

  int ans = n + 1;
  if (firstA != -1 && firstB != -1) {
    int x = lastB - firstA + 1;
    int y = lastA - firstA + 1;

    ans = x < y ? x : y;
  }

  if(ans > n) ans = 0;
  printf("%d", ans);

  return 0;
}
