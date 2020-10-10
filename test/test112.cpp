#include "iostream"
#include "algorithm"
#include "vector"

//198. 打家劫舍   小优化


using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0, len = nums.size();
        if(len == 0) return ans;

        int dp[100][2] = {0};
        dp[0][1] = nums[0];

        for(int i=1; i<len; ++i)
        {
            dp[i][0] = (dp[i-1][0] > dp[i-1][1])? dp[i-1][0]:dp[i-1][1];
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        ans = (dp[len - 1][0] > dp[len - 1][1])? dp[len - 1][0] : dp[len - 1][1];

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
