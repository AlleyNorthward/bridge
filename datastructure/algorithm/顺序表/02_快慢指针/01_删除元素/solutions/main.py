import sys

data = sys.stdin.buffer.read().split()
it = iter(data)
n = int(next(it))
x = int(next(it))

arr = [int(next(it)) for _ in range(n)]

slow = 0
for fast in range(n):
  if arr[fast] != x:
    arr[slow] = arr[fast];
    slow += 1

arr[:] = arr[:slow]

sys.stdout.write(' '.join(map(str, arr)) + '\n')
