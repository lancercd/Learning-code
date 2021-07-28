

class Dep {
    constructor(){
        this.subs = [];
    }

    add(watcher) {
        this.subs.push(watcher);
    }

    notify() {
        this.subs.forEach(watcher => watcher.update());
    }
}

class Watcher {
    constructor(callBack) {
        this.callBack = callBack;
    }

    update() {
        this.callBack();
    }
}

const w1 = new Watcher(() => {
    console.log('111');
});
const w2 = new Watcher(() => {
    console.log('222');
});
const w3 = new Watcher(() => {
    console.log('333');
});

const dep = new Dep();
dep.add(w1);
dep.add(w2);
dep.add(w3);

dep.notify();