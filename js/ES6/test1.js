let user = { name: 'lancercd', age: 16, height: 15.6 };
let arr = [4, 5, 4, 6, 34, 43, 23];


let obj = { ...user, ...arr };
console.log(obj);
console.log(...arr);