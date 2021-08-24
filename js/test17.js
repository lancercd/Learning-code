let arr = [2, 3, 5, 1, 4, 33, 1, 1, 5, 2];


let arr1 = Array.from(new Set(arr));

console.log(arr1);

function unique1(arr) {
  const res = [];
  const len = arr.length;
  for (let i = 0; i < len; ++i){
    if (res.indexOf(arr[i]) === -1) {
      res.push(arr[i]);
    }
  }

  return res;
}

console.log(unique1(arr));

function add(...args) {
  
}