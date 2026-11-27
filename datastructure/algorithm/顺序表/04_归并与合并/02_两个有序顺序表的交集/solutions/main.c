#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int *v1 = malloc(sizeof(int) * n);
  int *v2 = malloc(sizeof(int) * m);
  int *v3 = malloc(sizeof(int) * (n + m));

  int p1 = 0, p2 = 0, p3 = 0;

  for(int i = 0; i < n; ++i){
    scanf("%d",&v1[i]);
  }

  for(int i = 0; i < m; ++i){
    scanf("%d", &v2[i]);
  }

  while (p1 < n && p2 < m) {
    if (v1[p1] < v2[p2]) {
      ++p1;
    } else if (v1[p1] > v2[p2]) {
      ++p2;
    } else {
      int tmp = v1[p1];
      v3[p3++] = tmp;

      while (p1 < n && v1[p1] == tmp)
        ++p1;

      while (p2 < m && v2[p2] == tmp)
        ++p2;
    }
  }

  for (int i = 0; i < p3; ++i) {
    if (i > 0)
      printf(" ");
    printf("%d", v3[i]);
  }

  free(v3);
  free(v2);
  free(v1);
  return 0;
}
