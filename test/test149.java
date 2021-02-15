
public class test149{
    public static void main(String[] args)
    {
        int num = 8;
        // print(" 8:" + getBiteString(num));
        // print(" 0:" + getBiteString(0));
        // print(" 1:" + getBiteString(1));
        // print(" 2:" + getBiteString(2));
        // print("-1:" + getBiteString(-1));
        print("-2       :" + getBiteString(-2));


        print("-2  >>  1:" + getBiteString(-2 >> 1));
        print("-2  >>  1:" + (-2 >> 1));
        print("-2 >>>  1:" + getBiteString(-2 >>> 1));
        print("-2 >>>  1:" + (-2 >>> 1));

        print(" 2       :" + getBiteString(2));


        print(" 2  >>  1:" + getBiteString(2 >> 1));
        print(" 2  >>  1:" + (2 >> 1));
        print(" 2 >>>  1:" + getBiteString(2 >>> 1));
        print(" 2 >>>  1:" + (2 >>> 1));
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
