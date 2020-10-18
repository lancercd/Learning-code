#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size(), jump_to = 0;
        if(len < 2) return true;
        bool* arr = new bool[len];
        fill(arr, arr + len, 0);
        arr[0] = true;
        for(int i=0; i<len; ++i)
        {
            if(arr[i]){
                jump_to = min(len, i + nums[i] + 1);
                for(int j=i + 1; j<jump_to; ++j)
                {
                    arr[j] = true;
                }
            }
        }
        return arr[len - 1];
    }
};

int main() {
    vector<int> arr = {2,3,1,1,4};
    Solution* solu=  new Solution();
    cout << solu->canJump(arr);
    return 0;
}
