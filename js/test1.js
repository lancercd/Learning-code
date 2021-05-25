let arr = ["one", "two", "three"];
console.log(arr);

arr[10] = "10";

console.log(arr);
console.log(arr[6]);

arr.length = 1000;

console.log(arr);

// arr.length = 0;

console.log(arr);

if (arr instanceof Array) {
    console.log("is Array");
}
arr["name"] = 'lancercd';


if (arr instanceof Array) {
    console.log("is array");
} else {
    console.log("is not array");
}

arr["age"] = 20;

console.log(arr);
console.log(arr.length);