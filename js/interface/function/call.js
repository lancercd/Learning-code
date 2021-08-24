Function.prototype.MyCall = function (context) {
  let result;
  const symbol = Symbol();
  const args = [];
  for (let i = 1; i < arguments.length; ++i){
    args.push(arguments[i]);
  }

  context[symbol] = this;
  result = context[symbol](...args);
  delete context[symbol];

  return result;
}


const obj = {
  name: 'lancercd',
  age: 10
}


function test() {
  console.log(this.name);
  console.log(this.age);
}

test.MyCall(obj);
console.log(obj);