import {genRandArr} from "./include/ts/basic"

let array:number[] = genRandArr(10, -10, 10);
console.log(array);

function reverse(array: number[], start:number, end:number){
  while(start < end){
    let tmp:number = array[start];
    array[start] = array[end];
    array[end] = tmp;

    ++start;
    --end;
  }
}

reverse(array, 0, array.length-1);
console.log(array);
