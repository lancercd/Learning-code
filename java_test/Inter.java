
public class Inter{
    public static void main(String[] arg)
    {
        Dog dog = new Dog();
        dog.getKind();
    }
}

interface Animal{
    String kind = "Animal";
    void getKind();
    void name();
}

interface Beh{
    void run();
    void breathe();
    void eate();
}

class Dog implements Animal, Beh{
    public void getKind(){
        System.out.println(kind);
    }
    public void name(){

    }
    public void run(){

    }
    public void breathe(){

    }
    public void eate(){

    }
}
