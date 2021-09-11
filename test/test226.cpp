#include "iostream"
#include "algorithm"
#include "vector"
#include "stack"

using namespace std;

// 单调栈
// Tag leetcode 单调栈模板
// 单调栈模板

vector<int> nextGreaterElement(vector<int> arr) {
    const int len = arr.size();
    vector<int> ans(len);
    stack<int> s;

    for (int i = len - 1; i > -1; --i) {
        while (!s.empty() && s.top() <= arr[i]) s.pop();
        ans[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 1, 2, 4, 3};
    vector<int> ans = nextGreaterElement(arr);
    for (unsigned int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
