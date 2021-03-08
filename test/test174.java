import java.util.*;


public class test174{
    public static void main(String[] args)
    {
        doTest();
    }


    public static void doTest(){
        int[] arr = {-2,1,-3,4,-1,2,1,-5,4};
        Solution solu = new Solution();
        System.out.println(solu.maxSubArray1(arr));
    }
}



class Solution{

    public int maxSubArray1(int[] nums) {
        int len = nums.length;
        if(0 == len) return 0;
        int[] dp = new int[len];
        dp[0] = nums[0];
        int max = dp[0];
        for(int i=1; i<len; ++i)
        {
            dp[i] = Math.max(nums[i], nums[i] + dp[i-1]);
            max = Math.max(max, dp[i]);
        }
        return max;

    }


}
