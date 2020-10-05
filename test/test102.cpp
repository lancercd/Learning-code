#include "iostream"
#include "algorithm"
#include "climits"
#include "vector"


using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int current_max = nums[0];
        for(int i=1; i<k; ++i)
        {
            if(nums[i] > current_max) current_max = nums[i];
        }
        ans.push_back(current_max);

        for(unsigned int i=k; i < nums.size(); ++i)
        {
            if(nums[i] > current_max){
                current_max = nums[i];
            }
            ans.push_back(current_max);
        }


        return ans;
    }
};



int main() {
    int arr[] = {1,3,-1,-3,5,3,6,7};
    Solution* sol = new Solution();
    vector<int> nums(arr, arr + 8);
    vector<int> ans = sol->maxSlidingWindow(nums, 4);
    for(unsigned int i = 0; i<ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
