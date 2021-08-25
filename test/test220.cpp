#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        const int len = height.size();
        if(len < 3) return 0;

        int leftMax = height[0],
            rightMax = height[len - 1],
            l = 1,
            r = len - 2,
            ans = 0;

        while(l <= r){
            if(leftMax < rightMax) {
                ans += max(leftMax - height[l], 0);
                leftMax = max(leftMax, height[l++]);
            }else {
                ans += max(rightMax - height[r], 0);
                rightMax = max(rightMax, height[r--]);
            }
        }
        return ans ;
    }

};


int main() {
    Solution* solu = new Solution();
    vector<int> arr = { 0,1,0,2,1,0,1,3,2,1,2,1 };

    cout << solu->trap(arr) << endl;

    return  0;
}
