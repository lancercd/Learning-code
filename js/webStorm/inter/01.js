let arr = [2,4,1,6,1,6,3];

function unique1 (arr) {
    if (Array.isArray(arr)) throw new Error("请传入数组");
    return Array.from(new Set(arr));
}

function unique2(arr) {
    if (Array.isArray(arr)) throw new Error("请传入数组");

    let res = [];
    for (let i = 0; i < arr.length; i++) {
        if (res.indexOf(arr[i]) === -1) {
            res.push(arr[i])
        }
    }
    return res;
}

function unique3(arr) {
    if (Array.isArray(arr)) throw new Error("请传入数组");

    let res =[];
    for(let i = 0; i < arr.length; i++) {
        if(!res.includes( arr[i])) {
            res.push(arr[i]);
        }
    }
    return res;
}

function unique4(arr) {
    if (Array.isArray(arr)) throw new Error("请传入数组");

    arr = arr.sort();
    let res= [arr[0]];
    for (let i = 1; i < arr.length; i++) {
        let cur = i + 1;
        while(arr[i] === arr[cur] && cur < arr.length){
            ++cur;
        }

        if (arr[i] !== arr[i-1]) {
            res.push(arr[i]);
        }
    }
    return res;
}

function unique5(arr){
    return arr.filter((item,index) => {
        return arr.indexOf(item,0) === index;
    });
}

console.log(unique5(arr));