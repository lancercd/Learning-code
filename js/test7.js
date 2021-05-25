"use strict";

function a() {
    b();
}

function b() {
    console.log(arguments.callee.caller);
}

a();