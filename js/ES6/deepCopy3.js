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

let obj = Object.copy(data);

console.log(obj);