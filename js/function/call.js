
Function.prototype.myCall = function (context) {
  context = context || window;

  const func = Symbol(1);
  context[func] = this;

  let args = [];
  for (let i = 1; i < arguments.length; ++i) {
    args.push(arguments[i]);
  }

  const result = context[func](...args);

  delete context[func];
  return result;
}


Function.prototype.myApply = function (that, arr) {
  that = that || window;

  const func  = Symbol(1);

  that[func] = this;

  let result;

  if (!arr) {
    result = that[func]();
  } else {
    if (!Array.isArray(arr)) {
      throw new Error("params must be Array");
    }
    result = that[func](...arr);
  }

  delete that[func];

  return result;
}

Function.prototype.myBind = function (that, ...args1) {

  return (...args2) => {
    const func = Symbol(1);

    that[func] = this;

    let result = that[func](...args1.concat(args2))

    delete that[func];

    return result;
    // return this.myCall(that, ...args1.concat(args2));
  }
}

function show(a, b) {
  console.log(this.name, a, b);
}
show(1,2);

const obj = {
  name: 'obj.name'
}


// show.myCall(obj, 1, 2);
// show.myApply(obj, [1, 2]);

const bindShow = show.myBind(obj, 1);
bindShow(2);
bindShow(4);


console.log(obj);
