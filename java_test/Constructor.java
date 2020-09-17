
public class Constructor{
    // static{
    //     System.out.println("hello static blck");
    // }
    public static void main(String[] args)
    {
        // System.out.println("ok");
        // Constru a = new Constru();

        // a.main();
        // System.out.println(a.num);
        // Constru b = new Constru();

        Constru.Inner b = new Constru().new Inner(5);


    }
}

class Constru{
    static int num;

    public static void main(){
        System.out.println("main method");
    }
    public Constru(){
        // this(5);
        System.out.println("this is Constru's constructor");
        this.run();
    }
    public Constru(int num){
        System.out.println("this is Arg");
    }

    public void run(){
        // Inner a = new Inner();
        // a.show();
        // System.out.println(a.num);
    }
    // static{
    //     num = 5;
    //     System.out.println("hello static blck -----------------");
    // }

    //inner class
    class Inner{
        int num;
        public void Inner(){
            // this(5);g
            System.out.println("no arg");
        }
        public void Inner(int num){
            this.num = num;
            System.out.println("Inner constructor");
        }
        public void show(){
            System.out.println(" **** show ****");
        }
    }

}
