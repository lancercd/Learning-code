const pro = new Promise((resolve, reject) => {

    // resolve('ok');
    throw new Error('这是Error');
    reject('err');
})
.then(
    res => {
        console.log(111, 'success', res);
    },
    err => {
        console.log(222, 'fail', err);
    }
)
.then(
    res => {
        console.log(222, 'success', res);
    },
    err => {
        console.log(222, 'fail', err);
    }
).catch(err => {
    console.log('catch', err);
})