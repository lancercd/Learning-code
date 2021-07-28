const arr = [
    {
        name: 'a'
    },
    {
        name: 'zhangsan',
        age: 12
    },
    {
      name: 'b'
    },
    {
        name: 'xiaoming',
        age: 10,
        class: 'L2'
    }
]

// console.log(['xiaoming', 'zhangsan', 'a'].sort());


function sort1(arr) {
    return arr.sort((item1, item2) => item1 > item2);
}


function sort2(arr){
    let res = [].concat(arr);
    for (let i = 0; i < res.length - 1; ++i) {
        for (let j = 0; j < res.length - i -1; ++j) {
            if (res[j].name > res[j + 1].name) {
                let temp = res[j];
                res[j] = res[j + 1];
                res[j + 1] = temp;
            }
        }
    }
    return res;
}


function sort3(target){
    let res = [].concat(target);
    console.log(res);

    function cmp(item1, item2) {
        return item1 < item2;
    }
    function quick(arr, L, R){
        if(L >= R) return;
        let flag = arr[R];
        let l = L, r = R;
        while (l < r) {
            while(l < r && cmp(arr[l] , flag)){ ++l;}
            if(l < r) res[r--] = arr[l];
            while(l < r && !cmp(arr[r] , flag)){--r;}
            if(l < r) arr[l++] = arr[r];
        }
        arr[l] = flag;
        // quick(arr, 0, l - 1);
        // quick(arr, l + 1, R);
    }

    quick(res, 0, res.length - 1);

    return res;
}

console.log(sort3(arr));
