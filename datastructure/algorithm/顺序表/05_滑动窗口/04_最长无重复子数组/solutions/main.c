#include <stdlib.h>
#include <stdio.h>
int main(){
  int n;
  scanf("%d", &n);
  int* arr = malloc(sizeof *arr * n);

  for(int i = 0; i < n; ++i){
    scanf("%d", &arr[i]);
  }

  int* visited = calloc(101, sizeof*arr);
  int fast = 0, slow = 0;
  int max_len = -1;

  for(; fast < n; ++fast){
    int v = arr[fast];

    while(visited[v]){
      visited[arr[slow++]] = 0;
    }

    visited[v] = 1;
    int len = fast - slow + 1;
    max_len = len > max_len ? len : max_len;

  }

  printf("%d", max_len);

  free(visited);
  free(arr);
  return 0;
}

