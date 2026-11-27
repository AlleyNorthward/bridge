local n, x = io.read("*n", "*n")
local arr = {}

for i = 1, n do
  arr[i] = io.read("*n")
end

local slow=1
for fast=1, #arr do
  if arr[fast] ~= x then
    arr[slow] = arr[fast]
    slow = slow + 1
  end
end

for i=slow, #arr do
  arr[i]=nil
end

io.write(table.concat(arr, " "), "\n")
