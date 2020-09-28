#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        int sum = 0, len = height.size();
        if(len == 0) return 0;
        int* left = new int[len];
        int* right = new int[len];
        // vector<int> left(len), right(len);
        left[0] = height[0]; right[len-1] = height[len-1];
        for(int i=1; i<len; ++i)
        {
            if(height[i] > left[i-1]) left[i] = height[i];
            else left[i] = left[i-1];
        }
        for(int i=len - 2; i>=0; --i)
        {
            if(height[i] > right[i+1]) right[i] = height[i];
            else right[i] = right[i+1];
        }
        for(int i=1; i<len - 1; ++i)
        {
            sum += min(left[i], right[i]) - height[i];
        }

        return sum;
    }
};


int main() {
    int nums[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> arr(nums, nums + 12);

    Solution* solu = new Solution();
    cout << solu->trap(arr) << endl;

    return 0;
}
