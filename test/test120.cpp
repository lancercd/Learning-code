#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, len = height.size(), tmp;
        int* left = new int[len];
        int* right = new int[len];
        if(len < 2) return 0;
        left[0] = height[0]; right[len - 1] = height[len - 1];
        for(int i=1; i<len; ++i)
        {
            left[i] = max(left[i-1], height[i]);
        }
        for(int i=len - 2; i > -1; --i)
        {
            right[i] = max(right[i + 1], height[i]);
        }
        --len;
        for(int i=1; i<len; ++i)
        {
            tmp = min(left[i], right[i]) - height[i];
            if(tmp < 1) continue;
            ans += tmp;
        }

        return ans;
    }
};


int main() {
    vector<int> arr = {9, 0, 1};
    // vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution* solu = new Solution();
    cout << solu->trap(arr) << endl;
    return 0;
}
