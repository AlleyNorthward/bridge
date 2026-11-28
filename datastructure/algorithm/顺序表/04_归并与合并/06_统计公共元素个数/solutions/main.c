#include <stdio.h>
#include <stdlib.h>

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  int *v1 = malloc(sizeof(int) * n);
  int *v2 = malloc(sizeof(int) * m);
  int cnt = 0;

  for(int i = 0; i < n; ++i){
    scanf("%d", &v1[i]);
  }

  for(int i = 0; i < m; ++i){
    scanf("%d", &v2[i]);
  }

  int p1 = 0, p2 = 0;
  while(p1 < n && p2 < m){
    if(v1[p1] < v2[p2]){
      ++p1;
    } else if(v1[p1] > v2[p2]){
      ++p2;
    } else {
      ++cnt;
      int tmp = v1[p1];
      while(p1 < n && v1[p1] == tmp)
        ++p1;

      while(p2 < m && v2[p2] == tmp)
        ++p2;
    }
  }

  printf("%d", cnt);

  free(v2);
  free(v1);
  return 0;
}
