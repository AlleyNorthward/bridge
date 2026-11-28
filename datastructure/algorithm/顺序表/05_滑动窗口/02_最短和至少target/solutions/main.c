#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  long long target;
  scanf("%d%lld", &n, &target);

  int *arr = malloc((size_t)n * sizeof(*arr));
  if (!arr)
    return 1;

  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  long long sum = 0;
  int min_len = n + 1;
  int slow = 0, fast = 0;

  for (; fast < n; ++fast) {
    sum += arr[fast];
    while (sum >= target) {
      int len = fast - slow + 1;
      if (len < min_len)
        min_len = len;
      sum -= arr[slow++];
    }
  }

  if (min_len > n)
    min_len = 0;
  printf("%d\n", min_len);

  free(arr);
  return 0;
}
