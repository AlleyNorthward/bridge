declare const io:any
let p = 0;

const n: number = Number(io[p++]);
const x: number = Number(io[p++]);

const arr: number[] = [];
for (let i = 0; i < n; i++) {
  arr.push(Number(io[p++]));
}

function solve(arr:number[], x:number){

  let fast:number=0;
  let slow:number=0;

  for(;fast < arr.length; ++fast){
    if(arr[fast] != x)
      arr[slow++] = arr[fast];
  }
  arr.length = slow;
}

solve(arr, x);
io.write(arr.join(" ") + "\n");
