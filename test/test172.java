



public class test172{
    public static void main(String[] args)
    {
        int[] arr = {1,2,3,4,5,6};
        // int[] arr = {1,2,4,6,23,25,27,28,31,33,35,36,38,39,40,44,46,48,49,54,59};
        int target = 2;

        doTest(arr, target);
    }

    public static void doTest(int[] arr, int target){


        long start = System.currentTimeMillis();
        System.out.println(coinChange1(arr, target));
        long end = System.currentTimeMillis();
        System.out.println("time1:" + (end - start));


        start = System.currentTimeMillis();
        System.out.println(coinChange(arr, target));
        end = System.currentTimeMillis();
        System.out.println("time2:" + (end - start));
    }


    public static int coinChange(int[] arr, int target){
        int[][] dp = new int[arr.length + 1][target + 1];
        for(int i=0; i<dp.length; ++i)
        {
            for(int j=0; j < dp[i].length; ++j)
            {
                dp[i][j] = -1;
            }
        }
        return process(arr, 0, target, dp);
    }




    public static int process(int[] arr, int start, int rest, int[][] dp)
    {
        if(start == arr.length) return (rest == 0)? 1 : 0;
        if(dp[start][rest] != -1) return dp[start][rest];
        int cnt = 0;
        for(int i=0; (rest - arr[start] * i) >= 0; ++i)
        {
            int pre_rest = rest - arr[start] * i;
            if(dp[start + 1][pre_rest] != -1){
                cnt += dp[start + 1][pre_rest];
                continue;
            }
            cnt += process(arr, start + 1, pre_rest, dp);
        }
        dp[start][rest] = cnt;
        return cnt;
    }


    public static int coinChange1(int[] arr, int target){
        return process1(arr, 0, target);
    }


    public static int process1(int[] arr, int start, int rest)
    {
        if(start == arr.length || rest == 0) return (rest == 0)? 1 : 0;

        int cnt = 0;
        for(int i=0; (rest - arr[start] * i) >= 0; ++i)
        {
            cnt += process1(arr, start + 1, rest - arr[start] * i);
        }
        return cnt;
    }


    public static void print(String str){
        System.out.println(str);
    }
    public static void print(int str){
        System.out.println(str);
    }


}
