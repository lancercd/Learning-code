#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
class Solution {
public:
    vector<int> dp;
    int maxSubArray(vector<int>& nums) {
        dp.push_back(nums[0]);
        for(unsigned int i=1; i< nums.size(); ++i){
            if(dp[i-1] < 0) dp.push_back(nums[i]);
            else dp.push_back(nums[i] + dp[i-1]);
        }
        int max = -999;
        for(auto num:dp)
        {
            if(max < num) max = num;
        }
        return max;
    }
};
int main(int argc, char const *argv[]) {
    int array[] = {1, -2, 3, 10, -4, 7, 2, -5};
    vector<int> arr(array, array+8);
    Solution * a = new Solution;
    cout << a->maxSubArray(arr) << endl;
    return 0;
}
