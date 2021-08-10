

function instanceOf (target, origin){
    if(target === null || origin === null){
        return false;
    }

    let proto = Object.getPrototypeOf(target);

    while (proto !== null) {

        if (proto === origin.prototype) {
            return true;
        }
        proto = Object.getPrototypeOf(proto);
    }

    return false;
}


console.log(instanceOf([], Object));
console.log(instanceOf({}, Object));

class Base {}
class Child extends Base {}

const child = new Child();

console.log(instanceOf(child, Child));
console.log(instanceOf(child, Base));
console.log(instanceOf(child, Object));
console.log(instanceOf(child, String));
console.log(instanceOf("", String));
