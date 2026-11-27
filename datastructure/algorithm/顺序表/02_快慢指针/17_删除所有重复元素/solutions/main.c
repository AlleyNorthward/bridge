#include <stdlib.h>
#include <stdio.h>

#define N 2000003
#define EMPTY 0x3f3f3f3f

typedef struct hash_node{
  int val;
  int cnt;
}hash_node;

int find(hash_node* h, int x){
  int k = (x % N + N) % N;
  while(h[k].val != EMPTY && h[k].val != x){
    if(++k == N)
      k = 0;
  }

  return k;
}

int main(){
  int n;
  scanf("%d", &n);

  int * arr = malloc(sizeof(int) * n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &arr[i]);
  }

  hash_node* h = malloc(sizeof(hash_node) * N);
  for(int i = 0; i < N; ++i){
    h[i].val = EMPTY;
    h[i].cnt = 0;
  }

  for(int i = 0; i < n; ++i){
    int val = arr[i];
    int k = find(h, val);
    if(h[k].val == EMPTY)
      h[k].val = val;

    ++h[k].cnt;
  }

  int fast = 0, slow = 0;
  for(;fast < n; ++fast){
    int val = arr[fast];
    int k = find(h, val);
    if(h[k].cnt == 1){
      arr[slow++] = val;
    }
  }

  for(int i = 0; i < slow; ++i){
    if(i > 0) printf(" ");
    printf("%d", arr[i]);
  }

  free(h);
  free(arr);
  return 0;
}
