let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];


function randomSort(src) {
    let arr = src.slice();


}

// randomSort(arr);


const shuffle = arr => {
    arr.slice().sort(item => {
        parseInt(Math.random() * 2) - 1
    })
};


shuffle(arr);
console.log(arr);