let str1 = new String('ok');

let str2 = new String('ok');

let str3 = 'ok';
let str4 = 'ok';

console.log(str1 == str2);
console.log(str1 === str2);


console.log(str3 == str4);
console.log(str3 === str4);

console.log(str1 == str3);
console.log(str2 === str4);

console.log(Object.is(str1, str2));