
export default class MyPromise{
    static PADDING = "padding";
    static REJECT = 'reject';
    static RESOLVE = 'resolve';

    #aaa = '222';

    constructor(executor) {
        this.status = MyPromise.PADDING;
        this.rejectMethods = [];
        this.resolveMethods = [];
        this.catchMethods = [];

        

        try {
            console.log('#aaa', this.#aaa);
            executor(this.resolve.bind(this), this.reject.bind(this));
        } catch (error) {
            this.status = MyPromise.PADDING;
            this.reject(error);
        }


        //有异常丢给reject

    }

    reject(...args) {
        //mod status
        if (this.status !== MyPromise.PADDING) return;
        this.status === MyPromise.REJECT;

        //async exe
        this.#async(() => {
            try {
                //execut reject methods
                if (this.rejectMethods.length) {
                    // this.rejectMethods.map(fn => fn(...args));
                    return this.#exe('rejectMethods', args)
                } else {
                    //execut catch methods
                    return this.#exe('catchMethods', args)
                }
            } catch (e) {
                console.error(e);
            }
        })
    }




    resolve(...args) {
        
        if (this.status !== MyPromise.PADDING) return;
        this.status === MyPromise.RESOLVE;

        //async exe
        this.#async(() => {
            try {
                //execut resolve methods
                return this.#exe('resolveMethods', args)

            } catch (error) {
                this.status = MyPromise.PADDING;
                this.reject(error);
            }
        });
    }


    then(resolve, reject) {
       
        // add reject method in []
        this.rejectMethods.push((typeof reject === 'function') ? reject : () => { });
        
         // add resolve method in []
        this.resolveMethods.push((typeof resolve === 'function') ? resolve : () => { });
        
        //链式调用
        return this;
    }

    catch(onReject) {
        this.catchMethods.push(onReject);
        
        return this;
    }

        //执行数组中的方法
    #exe(methodsArrayName, args) {
        return this[methodsArrayName].reduce((res, fn, index) => {
            if (index == 0) return fn(...res);
            return fn(res);
        }, args);
    }

    
    //异步
    #async(fn) {
        setTimeout(fn());
    }

    static resolve() {
        return (new MyPromise()).resolve();
    }

    static reject() {
        return (new MyPromise()).reject();
    }


    static all() {
        
    }

    static race() {
        
    }
}
