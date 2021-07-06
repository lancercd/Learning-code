import java.util.Map;
import java.util.HashMap;

public class test192{
  public static void main(String[] args) {
    int[] nums = new int[]{0,1,3};
    Solution solu = new Solution();
    int num = solu.missingNumber(nums);

    System.out.println(num);
  }
}

class Solution {
    public int missingNumber(int[] nums) {
      int i = 0;
      for(i=0; i<nums.length; ++i){
        if(nums[i] != i) break;
      }
      return i;
    }
}
