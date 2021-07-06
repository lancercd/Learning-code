
const pro1 = new Promise((resolve, reject) => {
    resolve('111');
});
const pro2 = new Promise((resolve, reject) => {
    resolve('222');
});
const pro3 = new Promise((resolve, reject) => {
    resolve('333');
});


const proArr = [pro1, pro2, pro3];


//会拿到所有的结果
Promise.all(proArr)
    .then(res => {
        console.log(res);
    }, err => {
        console.log(err);
    })