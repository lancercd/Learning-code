
public class test150{

    public static void main(String[] args)
    {
        print(" 2 :" + getBiteString(2));
        print(" 1 :" + getBiteString(1));
        print("2^1:" + getBiteString(2^1));
    }


    public static String getBiteString(int num)
    {
        StringBuilder bite = new StringBuilder();
        for(int i=31; i>=0; --i)
        {
            bite.append((num >> i) & 1);
        }

        return bite.toString();
    }


    public static void print(String str)
    {
        System.out.println(str);
    }

    public static void print(int str)
    {
        System.out.println(str);
    }
}
