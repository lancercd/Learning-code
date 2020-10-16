#include "iostream"
#include "algorithm"
#include "vector"


using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0, len = nums.size();
        if(len == 0) return ans;

        int dp[2][2] = {0};
        dp[0][1] = nums[0];
        int idx = 1, pre = 0;
        for(int i=1; i<len; ++i)
        {
            dp[idx][0] = (dp[pre][0] > dp[pre][1])? dp[pre][0]:dp[pre][1];
            dp[idx][1] = dp[pre][0] + nums[i];
            pre = idx;
            idx = (idx == 1)? 0 : 1;
        }
        int ans1 = (dp[1][0] > dp[1][1])? dp[1][0] : dp[1][1];
        int ans2 = (dp[0][0] > dp[0][1])? dp[0][0] : dp[0][1];

        ans = (ans1 > ans2)? ans1 : ans2;

        return ans;
    }

};


int main() {
    vector<int> arr = {2,1,1,2};
    Solution* solu = new Solution();
    cout << solu->rob(arr);
    return 0;
}
