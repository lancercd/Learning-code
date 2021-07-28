
Array.prototype.myMap = function (fn, thisValue) {
    if(this === null){
        throw new Error('null of undefined');
    }
    if(typeof fn !== 'function'){
        throw new Error(fn + 'is not a function');
    }
    let context = this;
    let len = context.length;
    let res = [];

    for (let i = 0; i < len; ++i) {
        res.push(fn.call(thisValue, context[i], i, context));
    }
    return res;
}


const arr = [1,2,3,4,5];

let arr2 = arr.myMap((item, index) => {
    return item * index;
});

console.log(arr2);