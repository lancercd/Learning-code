const map = new Map();
const obj1 = {
  name: 'obj1',
  age: 12
}

const obj2 = {
  name: 'obj2',
  age: 12
}

let arr1 = [1,2,3,54];



map.set(obj1, 1);
map.set(obj2, 2);
map.set(arr1, obj1);
map.set(null, null);

// console.log(map.get(obj1));
// console.log(map.get(null));
// console.log(map.get(arr1));

for(let obj of map){
  console.log(obj);
}


const weakmap = new WeakMap();

// weakmap.set(null, 1);
// weakmap.get(null);
