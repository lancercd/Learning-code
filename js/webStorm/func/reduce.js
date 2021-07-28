let arr = [1, 2, 3, 4, 5, 6, 7];


arr.reduce((pre, cur) => {
    console.log(pre, cur);
    return pre + cur;
})