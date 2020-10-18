#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return true;
        for(int i=0; i<len; ++i)
        {
            nums[i] += i;
        }
        int index = 0, max_jump = nums[0];
        for(index  =0; index<len; ++index)
        {
            if(index > max_jump) break;
            if(nums[index] > max_jump) max_jump = nums[index];
        }


        return index >= len;
    }
};

int main() {
    Solution* solu=  new Solution();
    vector<int> arr = {0,1};
    cout << "0, 1      false = " << solu->canJump(arr) << endl;
    vector<int> arr1 = {1,0};
    cout << "1, 0      true = " << solu->canJump(arr1) << endl;
    vector<int> arr2 = {1, 0, 2};
    cout << "1, 0, 2   false = " << solu->canJump(arr2) << endl;
    vector<int> arr3 = {2,3,1,1,4};
    cout << "2,3,1,1,4 true = " << solu->canJump(arr3) << endl;
    vector<int> arr4 = {3,2,1,1,0};
    cout << "3,2,1,1,0 true = " << solu->canJump(arr4) << endl;
    return 0;
}
