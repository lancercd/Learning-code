#include "iostream"
#include "algorithm"
#include "vector"

// leetcode 42 接雨水 优化

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int cnt = 0, len = height.size(),water = 0;
        if(len == 0) return 0;
        int* left = new int[len];  fill(left, left + len, 0);
        int* right = new int[len]; fill(right, right + len, 0);
        left[0] = height[0];
        right[len - 1] = height[len - 1];
        for(int i=1; i < len; ++i)
        {
            left[i] = max(height[i], left[i - 1]);
        }
        // cout << "left" << endl;
        // for(int i=0; i<len; ++i){
        //     cout << left[i] << " ";
        // }

        for(int i=len - 2; i > -1; --i)
        {
            right[i] = max(right[i + 1], height[i]);
        }

        // cout << endl;
        // cout << "right" << endl;
        // for(int i=0; i<len; ++i)
        // {
        //     cout << right[i] << " ";
        // }
        // cout << endl;

        --len;
        for(int i=1; i<len; ++i){
            water = ((left[i] > right[i])? right[i] : left[i]) - height[i];
            if(water < 1) continue;
            cnt += water;
        }

        return cnt;
    }


};



int main() {
    vector<int> height = {2,0,2};
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution* solu = new Solution();
    cout << solu->trap(height) << endl;
    return 0;
}




























// class Solution {
// public:
//     int trap(vector<int>& height) {
//
//         int sum = 0, len = height.size();
//         if(len == 0) return 0;
//         int* left = new int[len];
//         int* right = new int[len];
//         left[0] = height[0]; right[len-1] = height[len-1];
//         for(int i=1; i<len; ++i)
//         {
//             if(height[i] > left[i-1]) left[i] = height[i];
//             else left[i] = left[i-1];
//         }
//         for(int i=len - 2; i>=0; --i)
//         {
//             if(height[i] > right[i+1]) right[i] = height[i];
//             else right[i] = right[i+1];
//         }
//         for(int i=1; i<len - 1; ++i)
//         {
//             sum += min(left[i], right[i]) - height[i];
//         }
//
//         return sum;
//     }
// };
