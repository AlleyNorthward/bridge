## question
给定一个升序排列的顺序表 L 和目标值 target,请查找 target 是否存在.

## 答案

```c
void solve(vector *vec) {
  int target = 20;
  int start = 0, end = vec->size-1;
  while(start <= end){
    int mid = start + (end - start) / 2;
    if(vec->data[mid] > target){
      end = mid-1;
    } else if (vec->data[mid] < target){
      start = mid+1;
    } else {
      printf("find it, pos: %d, num: %d\n", mid, vec->data[mid]);
      return;
    }
  }
  printf("not found\n");
}
```
