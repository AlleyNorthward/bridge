"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const basic_1 = require("./include/ts/basic");
let array = (0, basic_1.genRandArr)(10, -10, 10);
console.log(array);
function reverse(array, start, end) {
    while (start < end) {
        let tmp = array[start];
        array[start] = array[end];
        array[end] = tmp;
        ++start;
        --end;
    }
}
reverse(array, 0, array.length - 1);
console.log(array);
