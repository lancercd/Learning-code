#include "iostream"
#include "algorithm"
#include "vector"
#include "map"

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> table;
        vector<int>ans(2);
        for(int i=0; i<nums.size(); ++i)
        {
            int pre_index = table[target - nums[i]];
            if(pre_index){
                ans[0] = pre_index - 1;
                ans[1] = i;
                return ans;
            }else{
                table[nums[i]] = i + 1;
            }
        }
        return ans;
    }
};



int main() {
    Solution * solu = new Solution();
    vector<int> arr = {2,7,11,15};
    int target = 9;
    vector<int> ans = solu->twoSum(arr, target);
    cout << ans[0] << " " << ans[1];
    return 0;
}
