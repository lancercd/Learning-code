Function.prototype.MyApply = function (context, args) {
  let result;
  const symbol = Symbol();
  
  context[symbol] = this;

  if (!args) {
    result = context[symbol]();
  } else {
    if (!Array.isArray(args)) {
      throw new Error('params myst be array');
    }
    result = context[symbol](...args);
  }
  
  delete context[symbol];

  return result;
}


const obj = {
  name: 'lancercd',
  age: 10
}


function test(a, b, c) {
  console.log(this.name);
  console.log(this.age);
  console.log(a, b, c);

}

test.MyApply(obj, [1,2,3]);
console.log(obj);