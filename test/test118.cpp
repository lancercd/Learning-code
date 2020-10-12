#include "iostream"
#include "algorithm"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        map<int, int> table;
        map<int, int>::iterator it;
        table[nums[0]] = 0;
        for(int i=1; i<len; ++i)
        {
            it = table.find(target - nums[i]);
            if(it != table.end()) return {it->second, i};
            table[nums[i]] = i;
        }
        return {};
    }

};

int main() {
    vector<int> arr = {11, 15, 2, 7};

    Solution* solu = new Solution();

    vector<int> ans = solu->twoSum(arr, 9);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
