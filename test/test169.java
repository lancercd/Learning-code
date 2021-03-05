

public class test169{
    public static void main(String[] args)
    {
        int[] arr = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8, 15, 16, 7,7,12,12};
        printOddTimesNum(arr);
    }


    public static void printOddTimesNum(int[] arr)
    {
        int eor = 0, num1 = 0, num2 = 0;
        for(int i=0; i<arr.length; ++i)
        {
            eor ^= arr[i];
        }

        int flag = eor & (~eor + 1);

        for(int i=0; i<arr.length; ++i)
        {
            if((arr[i] & flag) != 0){
                num1 ^= arr[i];
            }else{
                num2 ^= arr[i];
            }
        }


        System.out.println(num1 + "  " + num2);
    }




}
