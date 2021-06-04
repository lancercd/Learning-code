function Artical() {
    this.url = "https://lancercd.top";

    this.get = function (params) {
        let str = Object.keys(params)
            .map(k => `${k}=${params[k]}`)
            .join('&');
        
        console.log(str);
    }
}


(new Artical()).get({
    id: 1,
    name: 'js'
})