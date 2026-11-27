#include <stdlib.h>
#include <stdio.h>

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  int* v1 = malloc(sizeof(int) * n);
  int* v2 = malloc(sizeof(int) * m);
  int size = m + n;
  int* v3 = malloc(sizeof(int) * size);

  for(int i = 0; i < n; ++i)
    scanf("%d", &v1[i]);

  for(int i = 0; i < m; ++i)
    scanf("%d", &v2[i]);

  int p1 = 0, p2 = 0, p3 = 0;

  while(p1 < n && p2 < m){
    if(v1[p1] <= v2[p2]){
      v3[p3++] = v1[p1++];
    } else {
      v3[p3++] = v2[p2++];
    }
  }

  while(p1 < n){
    v3[p3++] = v1[p1++];
  }

  while(p2 < m){
    v3[p3++] = v2[p2++];
  }

  for(int i = 0; i < p3; ++i){
    if(i > 0)
      printf(" ");
    printf("%d", v3[i]);
  }

  free(v1);
  free(v2);
  free(v3);
  return 0;
}
