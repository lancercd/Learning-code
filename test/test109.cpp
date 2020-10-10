#include "iostream"
#include "algorithm"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len = nums.size();
        int* arr = new int[len];
        std::fill(arr, arr + len, 0);
        for(int num : nums)
        {
            if(arr[num]) return num;
            else ++arr[num];
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
