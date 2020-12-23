package com.lancercd;

import com.lancercd.pojo.Dog;
import com.lancercd.pojo.Persion;
import com.lancercd.pojo.Student;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class DemoApplicationTests {


    @Autowired
    private Dog dog;

    @Autowired
    private Persion persion;

    @Autowired
    private Student student;


    @Test
    void contextLoads() {

        System.out.println("*******************************************");
        System.out.println(this.persion);
        System.out.println("*******************************************");

        System.out.println(this.student);
    }

}
