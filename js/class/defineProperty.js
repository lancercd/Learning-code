"use strict";
const user = {
    age: 18,
    height: 15.6
}


console.log(JSON.stringify(Object.getOwnPropertyDescriptor(user, 'age'), null, 2));


Object.defineProperty(user, 'age', {
    writable: false
});

//可以添加属性   但是添加的属性 writable enumerable configurable全为false
Object.defineProperty(user, 'name', {
    value: 'lancercd',
    // writable: false,
    // enumerable: true,
    configurable: true
});

Object.defineProperties(user, {
    age: {
        // writable: true,
        enumerable: false,
        configurable: false,
        get() {
            console.log('调用age 访问器');
            return 999;
        },
        set(value) {
            console.log('调用age 设置器');
        }
    },
    name: {
        value: 'lancercd',
        writeabele: false
    }
});

console.log("修改后");
console.log('name');
console.log(JSON.stringify(Object.getOwnPropertyDescriptor(user, 'name'), null, 2));
console.log('age');
console.log(JSON.stringify(Object.getOwnPropertyDescriptor(user, 'age'), null, 2));

//对 writable为false 的属性设置   设置不成功   且严格模式下会报错
//user.age = 99; // TypeError: Cannot assign to read only property 'age' of object '#<Object>'


console.log(user.name);
console.log(user);
console.log(user.age);