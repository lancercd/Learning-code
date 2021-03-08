


public class test171{
    public static void main(String[] args)
    {
        int[] arr = {4};
        int target = 3;
        System.out.println(coinChange(arr, target));
    }

    public static int coinChange(int[] arr, int target){
        return process(arr, 0, target);
    }


    public static int process(int[] arr, int start, int rest)
    {
        if(start == arr.length || rest == 0) return (rest == 0)? 1 : 0;

        int cnt = 0;
        for(int i=0; (rest - arr[start] * i) >= 0; ++i)
        {
            cnt += process(arr, start + 1, rest - arr[start] * i);
        }
        return cnt;
    }
}
