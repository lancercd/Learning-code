
!function () {
    function User(name) {
        this.name = name;
    }

    console.dir(User);
    console.dir(User.prototype);

    let instanse = new User.prototype.constructor('lancercd');

    console.log(instanse);
}();

console.log('ok');

+function () {
    function User(name) {
        this.name = name;

        this.show = function () {
            console.log(this.name);
        }
    }

    function createByObject(obj, ...args) {
        const constructor = Object.getPrototypeOf(obj).constructor;
        return new constructor(...args);
    }

    const user = new User('lancercd');

    const user2 = createByObject(user, 'user2');
    console.dir(user2);
    
}();