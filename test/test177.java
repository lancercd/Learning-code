

public class test177{
    public static void main(String[] args)
    {
        Solution solu = new Solution();
        int[] arr = {7,1,5,3,6,4};
        System.out.println(solu.maxProfit(arr));
    }
}

class Solution{
    public int maxProfit(int[] prices)
    {
        if(null == prices) return 0;
        int len = prices.length;
        if(len == 0 || len == 1) return 0;

        int min = prices[0], ans = 0;
        for(int i=1; i<len; ++i)
        {
            ans = Math.max(ans, prices[i] - min);
            if(prices[i] < min) min = prices[i];
        }

        return (ans < 1)? 0 : ans;
    }
}
