

public class test168{
    public static void main(String[] args)
    {
        int target = 30;
        printBite(target);
        printBite(~target);
        System.out.println(" ");
        System.out.println(~target + 1);

    }

    public static void printBite(int num){
        System.out.println();
        for(int i=31; i > -1; --i)
        {
            System.out.print((num >> i) & 1);
        }
    }



}
