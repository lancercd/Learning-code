
function User(){
    this.name = 'lancercd';
    this.age = 18;

    this.show = function () {
        console.log(this.name, this.age);
    }
}

function getInstance() {
    let instance = null;

    return function () {
        if (instance == null) {
            instance = new User();
        }
        return instance;
    }
}



let user1 = getInstance;
let user2 = getInstance;
console.log(user1 === user2);
