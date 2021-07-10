var lastRemaining = function(n, m) {
    const arr = [];
    let cnt = n - 1, index = -1, t = 0;

    for(let i=0 ;i<n; ++i) arr.push(i);

    while(true){
        console.log('index:' + index, 'cnt:' + cnt, 't:' + t, 'm:' + m);
        index = ++index % n;
        if(arr[index] == -1) continue;
        if(cnt == 0) break;
        ++t;

        //删除
        if(t == m){
            arr[index] = -1;
            t = 0;
            --cnt;
        }
    }

    return arr[index];
};

console.log(lastRemaining(3, 2));
