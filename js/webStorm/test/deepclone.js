const target = {
    name: 'lancercd',
    age: 18,
    arr: [
        1, 2, 3,
        [null, 2,
            {
                key:1,
                value:2,
                hh:function() {
                console.log('111')
                }
            }
        ]
    ],
    obj: {
        hh: 'hh',
        bb: 'bb'
    },
    fn: function() {
        console.log(fn)
    },
    date: new Date(),
    reg: new RegExp(),
    null: null,
    undefined: 'undefined',
    symbol: Symbol(2)
}

function deepClone(target){
    if(typeof target === 'symbol'){
        return Symbol.for(target.description);
    }else if (typeof target !== 'object') {
        return target;
    }else if (target === null){
        return null;
    }else if (Array.isArray(target)) {
        return target.map(item => deepClone(item));
    }else if (Object === target.constructor) {
        let res = {};
        for(let key in target){
            if(target.hasOwnProperty(key)){
                res[key] = deepClone(target[key]);
            }
        }
        return res;
    }

    return new target.constructor(target);
}
let cloned = deepClone(target);
target.arr.push(9999);
target.arr[3][2].key = 3;
console.log(cloned.arr[3][2].key);
console.log(deepClone(cloned));