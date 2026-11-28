#include <stdlib.h>
#include <stdio.h>

int main(){
  int n, k;
  scanf("%d%d", &n, &k);
  int* arr = malloc(sizeof(int) * n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &arr[i]);
  }

  long long sum = 0;
  for(int i = 0; i < k; ++i){
    sum += arr[i];
  }

  long long max = sum;
  for(int i = k; i < n; ++i){
    sum -= arr[i-k];
    sum += arr[i];

    max = sum > max ? sum : max;
  }

  printf("%lld", max);

  free(arr);
  return 0;
}
