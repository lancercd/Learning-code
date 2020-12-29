#include "iostream"
#include "algorithm"
#include "vector"
#include "unordered_map"

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        for(int i=0; i<nums.size(); ++i)
        {
            auto it = table.find(target - nums[i]);
            if(it != table.end()){
                return {it->second, i};
            }
            table[nums[i]] = i;
        }
        return {};
    }
};



int main() {
    Solution * solu = new Solution();
    vector<int> arr = {11, 7,15, 2};
    int target = 9;
    vector<int> ans = solu->twoSum(arr, target);
    cout << ans[0] << " " << ans[1];
    return 0;
}
