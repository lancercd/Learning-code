
console.log(1);
setTimeout(function(){
    console.log(2);
},0);
Promise.resolve(3)
    .then((val) =>{
        console.log(val);
    });
console.log(4);


