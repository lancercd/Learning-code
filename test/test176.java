

public class test176{
    public static void main(String[] args)
    {
        Solution solu = new Solution();
        int[] arr = {-2,1,-3,4,-1,2,1,-5,4};
        int sum = solu.maxSubArray(arr);
        System.out.println(sum);
    }
}


class Solution {
    public int maxSubArray(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int len = nums.length;
        int ans = nums[0];
        for(int i=1; i<len; ++i)
        {
            nums[i] = Math.max(nums[i], nums[i-1] + nums[i]);
            if(nums[i] > ans) ans = nums[i];
        }
        return ans;
    }
}
