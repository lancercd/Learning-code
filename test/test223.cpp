#include "iostream"
#include "algorithm"

using namespace std;

// 最长有效括号
// https://leetcode-cn.com/problems/longest-valid-parentheses/
// 动态规划


class Solution {
 public:
    int longestValidParentheses(string s) {
        const int len = s.size();
        if (len < 2) return 0;
        int *dp = new int[len], tmp = 0;
        fill(dp, dp + len, 0);

        for (int i = 1; i < len; ++i) {
            if (s[i] == '(') continue;
            tmp = i - 2;
            if (s[i - 1] == '(') {
                dp[i] = 2;
                if (tmp > -1) dp[i] += dp[tmp];
            } else {  // ')'
                tmp = i - dp[i - 1] - 2;
                if (dp[i - 1] != 0 && (tmp + 1) > -1 && s[tmp + 1] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (tmp > -1) dp[i] += dp[tmp];
                }
            }
        }

        //for (int i = 0; i < len; ++i) {
        //    cout << dp[i] << " ";
        //}
        //cout << endl;

        return *max_element(dp, dp + len);

    }
};

int main() {

    Solution *solu = new Solution();

    cout << solu->longestValidParentheses("") << endl;

    return 0;
}
