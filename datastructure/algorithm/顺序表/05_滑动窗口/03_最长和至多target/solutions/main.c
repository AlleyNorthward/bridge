#include <stdio.h>
#include <stdlib.h>
int main() {
  int n;
  long long target;
  scanf("%d%lld", &n, &target);
  int *arr = malloc(sizeof *arr * n);

  for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);

  long long sum = 0;
  int max_len = -1;
  int slow = 0, fast = 0;

  for (; fast < n; ++fast) {
    sum += arr[fast];

    while (sum > target) {
      sum -= arr[slow++];
    }
    int len = fast - slow + 1;
    max_len = len > max_len ? len : max_len;
  }

  if (max_len < 0)
    max_len = 0;
  printf("%d", max_len);

  free(arr);
  return 0;
}
