// const arr = [4, 1, 9, 1];
const arr = [4, 1, 9, 1, 1, 1, 1, 4, 1, 1, 1];

function handle(target) {
  const len = target.length;
  let res = new Array(len).fill(Number.MAX_VALUE);
  res[0] = 0;

  for(let i=0; i<len; ++i){
    for(let j=1; j<target[i]; ++j){
      let index = i + j;
      if(index >= len) continue;
      res[index] = Math.min(res[index], res[i] + 1);
    }
  }


  console.log(res);

  return res[len - 1];
}

console.log(handle(arr));
