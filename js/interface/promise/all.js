
function PromiseAll(promiseArray) {
  
  return new Promise((resolve, reject) => {
    if (!Array.isArray(promiseArray)) {
      return reject(new Error("请传入数组"));
    }

    let len = promiseArray.length;
    let cnt = 0;
    const res = new Array(len);

    for (let i = 0; i < len; ++i){
      Promise.resolve(promiseArray[i])
        .then(value => {
          ++cnt;
          res[i] = value;
          if (cnt >= len) resolve(res);
        })
        .catch(e => {
          reject(e);
        })
      }



  });
}

const pro1 = new Promise((res, rej) => {
  setTimeout(() => {
    res('1');
  }, 1000);
})

const pro2 = new Promise((res, rej) => {
  setTimeout(() => {
    res('2');
  }, 1000);
})

const pro3 = new Promise((res, rej) => {
  setTimeout(() => {
    res('3');
  }, 1000);
})


const proAll = PromiseAll([pro1, pro2, pro3])
  .then(res => {
    console.log(res);
  })
  .catch(e => {
    console.log(e);
  });