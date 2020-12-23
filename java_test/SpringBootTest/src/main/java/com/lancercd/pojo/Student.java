package com.lancercd.pojo;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.PropertySource;
import org.springframework.stereotype.Component;




@Component
//加载指定的配置文件
@PropertySource(value = "classpath:myStudent.properties")
public class Student {

    //取出配置文件中的  name    通过SEPL表达式
    @Value("${name}")
    private String name;

    //取出配置文件中的   age    通过SEPL表达式
    @Value("${age}")
    private int age;


    public Student() {
    }

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}
