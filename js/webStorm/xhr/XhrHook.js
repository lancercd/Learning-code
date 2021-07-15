

class XhrHook {
    constructor(beforeHooks = {}, afterHooks = {}){
        this.XHR = window.XMLHttpRequest;
        this.beforeHooks = beforeHooks;
        this.afterHooks = afterHooks;

        this.init();
    }

    init() {
        const that = this;
        window.XMLHttpRequest = function () {
            //这里的this是 本function中的this
            //创建 XMLHttpRequest 实例
            this.instance = new that.XHR();
            that.overwrite(this);
        }

    }

    overwrite(proxyXHR) {
        const instance = proxyXHR.instance;
        for (let key in instance) {

            // 代理函数
            if(typeof instance[key] === 'function'){
                this.proxyMethod(key, proxyXHR);
                continue;
            }

            // 代理属性
            this.proxyProperty(key, proxyXHR);

        }
    }

    //代理方法
    proxyMethod(key, proxyXHR) {
        let beforeHooks = this.beforeHooks;
        let afterHooks = this.afterHooks;

        proxyXHR[key] = (...args) => {

            //beforeHook 有对应的钩子  执行   如果返回的false  拦截
            if(beforeHooks[key] && beforeHooks[key].apply(proxyXHR, args) === false) return;

            //执行原生的方法        注意：这里一定要传入proxyXHR.instance  将这个具体的实例传进去
            const res = proxyXHR.instance[key].apply(proxyXHR.instance, args);

            //afterHook 有对应的钩子 执行
            afterHooks[key] && afterHooks[key].apply(proxyXHR, args);

            return res;
        }

    }


    //代理属性
    proxyProperty(key, proxyXHR) {
        Object.defineProperty(proxyXHR, key, this.getDescriptor(proxyXHR, key))
    }

    getDescriptor(proxyXHR, key) {
        const obj = Object.create(null);
        const that = this;

        obj.set = function (val) {
            if (!key.startsWith('on')) {
                proxyXHR.instance[key] = val;
                return;
            }

            proxyXHR.instance[key] = function (...args) {

                if(that.beforeHooks[key] && that.beforeHooks[key].call(proxyXHR) === false) return false;

                val.apply(proxyXHR.instance, args);

                that.afterHooks[key] && that.afterHooks[key].call(proxyXHR);
            }
        }

        obj.get = function () {
            return proxyXHR.instance[key];
        }

        return obj;
    }


}

new XhrHook({
    open: function () {
        console.log('open ---before');
        //return false;
    },
    onload: function () {
        console.log('onload ---before');
    },
    onreadystatechange: function () {
        console.log('onreadystatechange ---before');
    },
    onerror: function () {
        console.log('hook error ---before');
    }
},{
    open: function () {
        console.log('open ---after');
        //return false;
    },
    onload: function () {
        console.log('onload ---after');
    },
    onreadystatechange: function () {
        console.log('onreadystatechange ---after');
    },
    onerror: function () {
        console.log('hook error ---after');
    }
})

const xhr = new XMLHttpRequest();
xhr.open('GET', './data.json', true);
xhr.send();
xhr.onload = function(){

    if(xhr.status === 200){
        const msg = JSON.parse(xhr.responseText);
        console.log(msg);
    }
};
xhr.onreadystatechange = function () {
    console.log('onreadystatechange');
}
xhr.onerror = function(){
    console.log('onerror')
}