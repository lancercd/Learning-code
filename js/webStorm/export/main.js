import counter from './counter.js';

counter.name = 'bbb';


console.log(counter);


let obj1 = {
    name: 'aaa',
    age: 111,
    tostring() {
        return 'lancercd1111'
    }
}

let obj2 = {
    name: 'bbb',
    age: 111,
    tostring() {
        return 'lancercd222'
    }
}


let arr1 = [1, 2, 3];
let arr2 = [4, 5, 6, 7];
function fn1() {}
function fn2() {}

let number = arr1.reduce((pre, cur) =>  pre + cur, 0);
console.log(number);
let obj3 = {
    [obj1]: '111',
    [obj2]: '222'
}


console.log([obj1].toString());
console.log(obj3);