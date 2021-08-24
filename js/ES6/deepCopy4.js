
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

function clone(data) {
  if (typeof data === 'symbol') {
    return Symbol.for(data.description);
  } else if (typeof data != 'object') {
    return data;
  } else if (data == null) {
    return null;
  }
   else if (data instanceof Array) {
    return data.map(item => clone(item));
  } else if (data.constructor === Object) {
    let res = {};
    for (let key in data) {
      res[key] = clone(data[key]);
    }

    return res;
  } else {
    return new data.constructor(data);
  }
}

const data2 = clone(data);

console.log(data2);