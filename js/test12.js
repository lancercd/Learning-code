let arr = [5, 7, 6, 1, 12, 5, 36];

console.log(Math.max(...arr));
console.log(Math.max.apply(Math, arr));
console.log(Math.max.call(Math, ...arr));