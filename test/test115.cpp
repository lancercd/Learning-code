#include "iostream"
#include "algorithm"
#include "vector"

// leetcode 42 接雨水 先来个暴力

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int cnt = 0, len = height.size(), left_max = 0, right_max = 0, water = 0;
        for(int i=1; i<len; ++i)
        {
            left_max = find_left_max(i, height);
            right_max = find_right_max(i, height);
            if(left_max <= height[i] || right_max <= height[i]) continue;
            water = ((left_max > right_max)? right_max : left_max) - height[i];
            if(water < 1) continue;
            cnt += water;
        }

        return cnt;

    }

    int find_left_max(int end, vector<int>& height){
        int max = 0;
        for(int i=0; i<end; ++i){
            if(height[i] > max) max = height[i];
        }
        return max;
    }


    int find_right_max(int start, vector<int>& height){
        int max = 0, len = height.size();
        for(int i=start + 1; i<len; ++i){
            if(height[i] > max) max = height[i];
        }
        return max;
    }
};



int main() {
    vector<int> height = {0,3,0,1,0};
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
