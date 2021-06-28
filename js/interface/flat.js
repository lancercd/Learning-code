const data = [1, [3, 523, 42], 1, 3, 25, [4], 88, [1, 2, 4, 6, 7, 3]];


let res = [];
function flat1(data) {
    
    if (Array.isArray(data)) {
        data.forEach((item) => {
            flat(item);
        });
    } else {
        res.push(data);
    }
    
}


function flat2(data) {
    for (let i = 0; i < data.length; ++i) {
        if (typeof data[i] === 'number') {
            res.push(data[i]);
            continue;
        }
        flat2(data[i]);
    }
}



// flat1(data);
flat2(data);

console.log(res);