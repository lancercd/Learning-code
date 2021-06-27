const obj = {
    php: 99,
    linux: 100,
    C: 10,
    java: 60
}


console.log(Object.keys(obj));
console.log(Object.entries(obj));
console.log(Object.values(obj));

console.log(Math.max.call(Math, ...Object.values(obj)));

console.log(Math.max.apply(Math, Object.values(obj)));