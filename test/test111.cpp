#include "iostream"
#include "algorithm"
#include "vector"

//198. 打家劫舍   test112.cpp 优化


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
            dp[i][0] = find_max(i, 0, dp);
            dp[i][1] = find_max(i-1, 1, dp) + nums[i];
        }
        // show(len, dp);
        int tmp1 = find_max(len, 0, dp);
        int tmp2=  find_max(len, 1, dp);
        ans = (tmp1 > tmp2)? tmp1 : tmp2;

        return ans;
    }

    // void show(int len, int arr[][2]){
    //     for(int i=0; i<len; ++i)
    //     {
    //         cout << arr[i][0] << " ";
    //     }
    //     cout << endl;
    //     for(int i=0; i<len; ++i)
    //     {
    //         cout << arr[i][1] << " ";
    //     }
    //     cout << endl;
    // }

    int find_max(int max_idx, int flag, const int arr[][2]){
        int max = 0;
        for(int i=0; i<max_idx; ++i){
            if(arr[i][flag] > max) max = arr[i][flag];
        }
        return max;
    }
};


int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    vector<int> nums = {2,7,9,3,1};
    Solution* solu = new Solution();

    cout << solu->rob(nums) << endl;


    return 0;
}
