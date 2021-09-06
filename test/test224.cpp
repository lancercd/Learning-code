#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

// 接雨水
// https://leetcode-cn.com/problems/trapping-rain-water/
// 双指针

class Solution {
 public:
    int trap(vector<int> &arr) {
        int len = arr.size();
        if (len < 3) return 0;
        int ans = 0, l = 1, r = len - 2, L = arr[0], R = arr[len - 1];

        while (l <= r) {
            if (L < R) {
                ans += max(0, L - arr[l]);
                L = max(L, arr[l++]);
            } else {
                ans += max(0, R - arr[r]);
                R = max(R, arr[r--]);
            }
        }

        return ans;
    }
};
int main() {

    Solution *solu = new Solution();

    vector<int> arr = {4, 2, 0, 3, 2, 5};

    cout << solu->trap(arr) << endl;
    return 0;
}
