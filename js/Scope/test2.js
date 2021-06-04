let data = [
    {
        name: 'x',
        age: 10,
        height: 156.2
    },
    {
        name: 'a',
        age: 4,
        height: 45.2
    },
    {
        name: 'r',
        age: 56,
        height: 453.2
    },
    {
        name: 'h',
        age: 10,
        height: 75.74
    }
];

function order(key, type = 'asc') {

    return function (obj1, obj2) {
        if (type == 'asc') {
            return (obj1[key] < obj2[key]) ? -1 : 1;
        } else {
            return (obj1[key] < obj2[key]) ? 1 : -1;
        }
    }
}


console.log(data.sort(order('age', 'asc')));
/*
[
  { name: 'a', age: 4, height: 45.2 },
  { name: 'h', age: 10, height: 75.74 },
  { name: 'x', age: 10, height: 156.2 },
  { name: 'r', age: 56, height: 453.2 }
]
*/

console.log(data.sort(order('height', 'desc')));
/*
[
  { name: 'r', age: 56, height: 453.2 },
  { name: 'x', age: 10, height: 156.2 },
  { name: 'h', age: 10, height: 75.74 },
  { name: 'a', age: 4, height: 45.2 }
]
*/