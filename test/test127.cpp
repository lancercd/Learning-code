#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return true;
        int Max = nums[0], cur = 0;
        for(int i=1; i<len; ++i)
        {
            if(i > Max) break;
            cur = nums[i] + i;
            if(cur > Max){
                Max = cur;
            }
        }
        return Max >= (len - 1);
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
