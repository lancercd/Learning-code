function User() {
    this.name = "lancercd";
    this.age = 10;

    this.show = function() {
        console.log("this is User's show");
    }
}



console.dir(User);


// User.__proto__.show = function () {
//     console.log("this is User.__proto__.show");
// }

User.show();
// (new User).show();