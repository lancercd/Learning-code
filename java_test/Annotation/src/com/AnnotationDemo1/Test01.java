package com.AnnotationDemo1;

public class Test01 extends Object{


    @Override
    public String toString(){
        return super.toString();
    }

    @Deprecated
    public static void Test(){
        System.out.println("Deprecated  Annotation");
    }

    @Deprecated
    public static void deprecated(){
        Test();
    }

    public static void main(String[] args){
        Test();
    }
}
