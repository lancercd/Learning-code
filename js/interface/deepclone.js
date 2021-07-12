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


function deepClone(data) {
  if (typeof data === 'symbol') {
    return new Symbol.for(data.description);
  } else if (data === null) {
    return null;
  } else if (typeof data !== 'object') {
    return data;
  } else if (data instanceof Array) {
    return data.map(item => deepClone(item));
  } else if (data.constructor == Object) {
    let obj = {};
    for (let key in data) {
      if (data.hasOwnProperty(key)) {
        obj[key] = deepClone(data[key]);
      }
    }
    return obj;
  } else {
    return new data.constructor(data);
  }
}

const cloned = deepClone(data);
cloned2.address.detail.push("*******");
console.log(data);
// console.log(cloned.bwh[4].fun());