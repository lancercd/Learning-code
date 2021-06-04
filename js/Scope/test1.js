var var_arr = [];

for (var var_i = 0; var_i < 10; ++var_i){
    var_arr.push(function () { return var_i;})
}

console.log(var_i);    // 10
console.log(var_arr[0]()); // 10
console.log(var_arr[1]()); // 10
//全都为10


var let_arr = [];

for (let let_i = 0; let_i < 10; ++let_i){
    let_arr.push(function () { return let_i;})
}
// console.log(let_i);      //ReferenceError: let_i is not defined
console.log(let_arr[0]());  // 0
console.log(let_arr[1]());  // 1