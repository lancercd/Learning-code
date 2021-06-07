const user = {
    name: 'lancercd',
    age: 12
};

console.log(Object.getOwnPropertyDescriptor(user, 'name'));
/*
{
  value: 'lancercd',
  writable: true,
  enumerable: true,
  configurable: true
}
*/

