#include "iostream"
#include "algorithm"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size(),cur,key;
        vector<int> ans(2);
        map<int, int> arr;
        arr[nums[0]] = 0;
        for(int i=1; i<len; ++i)
        {
            cur = nums[i];
            key = target - cur;
            if(find(arr, key)){
                ans[0] = arr[key];
                ans[1] = i;
                return ans;
            }
            arr[cur] = i;
        }
        return ans;

    }

    bool find(map<int, int>& arr, int target){
        auto it = arr.find(target);
        if(it != arr.end()) return true;
        return false;
    }

};

int main() {
    vector<int> arr = {11, 15, 2, 7};

    Solution* solu = new Solution();

    vector<int> ans = solu->twoSum(arr, 9);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
