#include "iostream"
#include "algorithm"
#include "vector"
#include "stack"
#include "map"

using namespace std;

// leetcode
// 单调栈
// 496. 下一个更大元素 I
// https://leetcode-cn.com/problems/next-greater-element-i/

class Solution {
 public:
    vector<int> nextGreaterElement(vector<int> &arr1, vector<int> &arr2) {
        const int len1 = arr1.size(), len2 = arr2.size();
        vector<int> ans(len1);
        stack<int> s;
        map<int, int> m;

        for (int i = len2 - 1; i > -1; --i) {
            while (!s.empty() && s.top() <= arr2[i]) s.pop();

            m.insert(make_pair(arr2[i], s.empty() ? -1 : s.top()));
            s.push(arr2[i]);
        }

        for (int i = 0; i < len1; ++i) {
            ans[i] = m[arr1[i]];
        }
        return ans;
    }
};
int main() {
    //vector<int> arr1 = {4, 1, 2}, arr2 = {1, 3, 4, 2};
    vector<int> arr1 = {2, 4}, arr2 = {1, 2, 3, 4};
    Solution *solu = new Solution();

    vector<int> ans = solu->nextGreaterElement(arr1, arr2);

    for (unsigned int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
