class Ve{
    constructor(name) {
        this.name = name;
        this.sayHello();
    }

    cmpThis(otherThis) {
        console.log(this === otherThis);
        console.log(Object.is(this, otherThis));
    }

}

class Bus extends Ve{
    constructor(name) {
        super(name);

        this.cmpThis(this);
    }

    sayHello() {
        console.log('hello');
    }
 }


console.log(new Bus('lancercd'));
