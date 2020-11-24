package com.test;

public class Persion {
    public String name;

    public int age;

    public Persion(){

    }

    public Persion(String name , int age){
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return "Persion{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}
