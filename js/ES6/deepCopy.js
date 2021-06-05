'use strict';

//深拷贝

const data = {
    name: 'lancercd',
    age: 20,
    address: {
        city: '重庆',
        town: '大学城',
        detail: ['虎溪街', '重庆师范大学', '清风A']
    },
    bwh: [1, 2, 3, 4, { l: 20, w: 'ok', fun: function () { return 1; } }],
    func: function () {
        return 'func'
    },
    date: new Date,
    err: new Error,
    reg: new RegExp(),
    null: null,
    undefined: undefined
}


//通过递归 完成 深拷贝
function copy1(target) {
    let res = target instanceof Array ? [] : {};
    
    for (const [key, value] of Object.entries(target)) {
        
        // console.log(`key:${key} value:${value}`);
        res[key] = (typeof value == 'Object')?copy(value) : value;
    }

    return res;
}



//不能拷贝  function   不能拷贝某些数据类型
function copy2(target) {
    let strTarget = JSON.stringify(target, null, 2);
    console.log(strTarget);
    // return JSON.parse(strTarget);
}


let copiedData1 = copy1(data);
// console.log(copiedData1);


let copiedData2 = copy2(data);
console.log(copiedData2);



Object.copy(d)

