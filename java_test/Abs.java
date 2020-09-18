
public class Abs{
    public static void main(String[] arg)
    {
        Dog dog = new Dog();
        dog.run();
    }
}

abstract class Animal{
    public Animal(){
        System.out.println("this is Animal constructor");
    }

    abstract void run();
}

abstract class Beh extends Animal{
    public Beh(){
        System.out.println("Beh Constructor");
    }
}

class Dog extends Beh{
    public void run(){
        System.out.println("run");
    }
}
