
public class Ext{
    // static{
    //     System.out.println("hello static blck");
    // }
    public static void main(String[] args)
    {
        Animal a = new Animal(4);
        // Animal a = new Animal();


    }
}
class Dog{
    public int number;
    public Dog(){
        System.out.println("this is Dog constructor");
    }

    public Dog(int num){
        this.number = num;
        System.out.println("the num is" + num);
        System.out.println("this is Dog constructor");
    }

    public void show(){
        System.out.println("show method");
    }
}

class Animal extends Dog{
    public Animal(){
        System.out.println("Animal's constructor");
    }
    public Animal(int num){
        super(4);
        super.show();
        System.out.println(super.number);
        System.out.println("Animal Arg");
    }

}
