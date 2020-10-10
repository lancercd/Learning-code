#include "iostream"
#include "algorithm"
#include "vector"

//198. 打家劫舍   小优化  使用滚动数组


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
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    vector<int> nums = {1,2,3,1};
    // vector<int> nums = {2,7,9,3,1};

    Solution* solu = new Solution();

    cout << solu->rob(nums) << endl;


    return 0;
}
