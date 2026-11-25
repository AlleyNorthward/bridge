function getRandomInt(min: number, max: number): number {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function genRandArr(len: number, min: number, max: number, isUnique: number = 0): number[] {
  const arr: number[] = [];
  const set = new Set<number>();
  const total = max - min + 1;

  if (isUnique === 1 && len > total) {
    throw new Error(`区间 [${min},${max}] 最多只有 ${total} 个不同数字，无法生成长度 ${len} 的无重复数组`);
  }

  while (arr.length < len) {
    const val = getRandomInt(min, max);
    if (isUnique === 0) {
      arr.push(val);
    } else {
      if (!set.has(val)) {
        set.add(val);
        arr.push(val);
      }
    }
  }
  return arr;
}

export {genRandArr}
