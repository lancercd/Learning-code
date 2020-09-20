import java.util.HashSet;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Solution a = new Solution();
        Scanner in = new Scanner(System.in);
        String str = in.next();

        System.out.println(a.longestDupSubstring(str));
    }
}


class Solution {
    public String longestDupSubstring(String S) {
		int len = S.length();
        int a = 26;
        long module = (long) Math.pow(2, 32);
        if(len <= 1)
            return "";
        int[] nums = new int[len];
        for(int i = 0; i < len; i++){
            nums[i] = (int) S.charAt(i) - (int) 'a';
        }
        int low = 1;
        int high = len;
        while(low != high) {
        	int L = (high-low)/2 + low;
        	if(search(L, a, module, nums) != -1)
        		low = L + 1;
        	else
        		high = L;
        }
        int start = search(low-1, a, module, nums);
        if(start == -1)
        	return "";
        else
        	return S.substring(start, start+low-1);
    }

	public int search(int L, int a, long module, int[] nums) {
		int len = nums.length;
		HashSet<Long> hashSet = new HashSet<Long>();
        long tmp = 0;
        long aL = 1;
        for(int j = 0; j < L; j++){
            tmp = (tmp *a + nums[j]) % module;
            //System.out.println(tmp);
            aL = (aL*a) % module;
        }
        hashSet.add(tmp);
        for(int j = 1; j <= len - L; j++){
            tmp = (tmp*a - nums[j-1]*aL%module + module) % module;
            tmp = (tmp + nums[j+L-1]) % module;
            if(hashSet.contains(tmp))
                return j;
            hashSet.add(tmp);
        }
		return -1;
	}
}
