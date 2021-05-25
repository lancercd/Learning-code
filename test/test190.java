

public class test190{
    public static void main(String[] args)
    {
        Solution solu = new Solution();

        int[] arr = {1,1};

        System.out.println(solu.maxArea(arr));
    }
}


class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        int left = 0;
        int right = height.length - 1;
        while(left < right)
        {
            max = Math.max(max, Math.min(height[left], height[right]) * (right - left));
            if(height[left] < height[right]) ++left;
            else --right;
        }
        return max;
    }
}
