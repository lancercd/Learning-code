#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = (int)nums.size();
        if(len == 0) return 0;
        int* dp = new int[len];
        fill(dp, dp + len, 0);
        dp[0] = 1;
        for(int i=1; i<len; ++i)
        {
            int current_max = 0;
            for(int j=0; j < i; ++j)
            {
                if(nums[j] < nums[i] && dp[j] > current_max) current_max =dp[j];
            }
            dp[i] = current_max + 1;
        }

        int ans = dp[0];
        for(int i=1; i<len; ++i)
        {
            if(dp[i] > ans) ans = dp[i];
        }
        return ans;
    }
};



int main() {
    int arr[] = {10,9,2,5,3,7,101,18};
    vector<int> nums(arr, arr + 8);


    Solution * solu = new Solution();
    cout << " ok" << endl;
    cout << solu->lengthOfLIS(nums) << endl;
    return 0;
}
