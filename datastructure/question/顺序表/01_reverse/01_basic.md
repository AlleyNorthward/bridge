## question
- 设计一个高效算法, 将顺序表L的所有元素逆置, 空间复杂度为O(1)

```c
void solve(vector *vec) {
  int start = 0, end = vec->size-1;

  while(start<end){
    int tmp = vec->data[start];
    vec->data[start]=vec->data[end];
    vec->data[end]=tmp;

    ++start;
    --end;
  }

}
```
