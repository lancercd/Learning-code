//Promise.race 进行并发控制

const urls = [
    {info:'link1', time: 1000},
    {info:'link2', time: 1500},
    {info:'link3', time: 500},
    {info:'link4', time: 2000},
    {info:'link5', time: 2500},
    {info:'link6', time: 1000},
    {info:'link7', time: 300},
    {info:'link8', time: 1500}
];

function limitLoad(data, handler, limit) {
    if (!Array.isArray(data) || typeof handler !== 'function' || limit === 0) {
        throw new Error('参数错误');
    }

   // 1.拷贝数据
    let urls = [].concat(data);

    let promises = urls.splice(0, limit).map((url, index) => {
        return handler(url).then(() => {
            return index;
        })
    })


    let p = Promise.race(promises);
    for (let i = 0; i < urls.length; ++i) {
        p = p.then(index => {
            promises[index] = handler(urls[i]).then(res => {
                return index;
            })

            return Promise.race(promises);
        });
    }

}

function loadImg(url) {
    return new Promise((resolve, reject) => {
        console.log('-----' + url.info + 'start');
        setTimeout(() => {
            console.log(url.info + 'ok!!!');
            resolve();
        }, url.time);
    })
}


limitLoad(urls, loadImg, 3);
