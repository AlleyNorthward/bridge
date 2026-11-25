## qustion
- 给定一个只包含正整数的数组 arr,以及一个正整数 target.
- 
- 请找出一个连续子数组，使得：
- sum \le target
- 
- 返回满足条件的最长连续子数组的长度。
- 
- 示例：
- arr = {2, 1, 3, 2, 1, 1, 4};
- target = 5;
- 
- 其中:
- [2, 1, 3]    sum = 6  不满足
- [2, 1]       sum = 3  length = 2
- [1, 3]       sum = 4  length = 2
- [3, 2]       sum = 5  length = 2
- [2, 1, 1]    sum = 4  length = 3
- [1, 1, 4]    sum = 6  不满足
- 
- 
- 答案:3

## 答案
```c
void solve(vector *vec) {
  int target = 5;
  int slow = 0, fast = 0;
  int sum = 0;
  int max = 0;

  for (; fast < vec->size; ++fast) {
    sum += vec->data[fast];

    while (sum > target) {
      sum -= vec->data[slow++];
    }

    int len = fast - slow + 1;

    if (len > max)
      max = len;
  }

  printf("%d\n", max);
}
```
