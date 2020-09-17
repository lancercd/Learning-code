import java.util.Scanner;

public class Test1{
    public static void main(String[] args)
    {
        // final int num = 1;
        // System.out.println(num);
        Per a = new Per();
        Per b = new Per(1);
        a = null;
        b = null;


        System.gc();
    }
}


class Per{
    int num;
    public Per(){
        System.out.println("this is Per constructor");
    }
    public Per(int num){
        this.num = num;
        System.out.println("this is Per arg constructor");
    }
    public void finalize(){
        System.out.println("destructor Per");
    }
}
