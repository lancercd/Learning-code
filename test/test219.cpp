#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        int len = height.size();
        if (len < 3) return 0;

        int ans = 0,
            *leftArr = new int[len],
            *rightArr = new int[len];

        leftArr[0] = height[0]; rightArr[len - 1] = height[len - 1];

        for (int i = 1; i < len; ++i) leftArr[i] = max(leftArr[i - 1], height[i]);
        for (int i = len - 2; i > -1; --i) rightArr[i] = max(rightArr[i + 1],  height[i]);

        --len;
        for(int i=1; i<len; ++i){
            int m = min(leftArr[i - 1], rightArr[i + 1]) - height[i];
            if(m < 1) continue;
            ans += m;
        }


        return ans;
    }

};


int main() {
    Solution* solu = new Solution();
    vector<int> arr = { 0,1,0,2,1,0,1,3,2,1,2,1 };

    cout << solu->trap(arr) << endl;

    return  0;
}
