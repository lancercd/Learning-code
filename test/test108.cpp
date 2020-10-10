#include "iostream"
#include "algorithm"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int, int> ma;
        for(int num : nums)
        {
            if(ma[num]) return num;
            else ++ma[num];
        }
        return -1;
    }
};



int main() {
    int arr[] = {2, 3, 1, 0, 2, 5, 3};
    vector<int> nums(arr, arr + 7);
    Solution* solu = new Solution();
    int ans = solu->findRepeatNumber(nums);

    cout << ans << endl;

    return 0;
}
