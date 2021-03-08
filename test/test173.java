import java.util.*;


public class test173{
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

    //暴力
    public int maxSubArray1(int[] nums) {
        int max = Integer.MIN_VALUE;

        int len = nums.length;
        for(int i=0; i<len; ++i)
        {
            int sum = 0;
            for(int j=i; j<len; ++j)
            {
                sum += nums[j];
                if(max < sum) max = sum;
            }
        }
        return max;
    }




    public static void print(String str){
        System.out.println(str);
    }
    public static void print(int num){
        System.out.println(num);
    }


}
