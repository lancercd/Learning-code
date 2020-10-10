#include "iostream"
#include "algorithm"
#include "vector"

//213. 打家劫舍2  先来个暴力


using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        return max(DP(0, len - 1, nums), DP(1, len, nums));
    }


    int DP(const int start, const int end, const vector<int>& arr){
        int ch = 0, not_ch = 0, tmp = 0;
        for(int i = start; i < end; ++i)
        {
            tmp = not_ch;
            not_ch = max(not_ch, ch);
            ch = tmp + arr[i];
        }
        return max(ch, not_ch);
    }

};


int main() {
    // std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    vector<int> nums = {1,2,3,1};
    // vector<int> nums = {2,7,9,3,1};

    Solution* solu = new Solution();

    cout << solu->rob(nums) << endl;


    return 0;
}
