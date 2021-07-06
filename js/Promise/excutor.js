
// new Promise(excutor)
// excutor 是同步执行
//      也就是说在Promise里面是同步的
const promise = new Promise((res, rej) => {
    console.log(1);
    res('111');
});


// 但是then 是余部执行
// 会等待其他任务执行完  才执行then中的方法
promise.then((info) => {
    console.log('then');
}, () => {
    console.log('reject');
})

console.log(2);


/*
    console 
1
2
then

 */