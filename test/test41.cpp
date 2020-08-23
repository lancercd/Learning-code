#include "iostream"
#include "algorithm"
#include "utility"
#define _t first
#define _v second
using namespace std;
const int MAXN = 1e3 + 5;
pair<int, int> arr[105];
int dp[MAXN];
int main(int argc, char const* argv[]) {
    int T, M; cin >> T >> M;
    for (int i = 0; i < M; ++i) cin >> arr[i]._t >> arr[i]._v;
    fill(dp, dp + T + 5, -1); dp[0] = 0; dp[arr[0]._t] = arr[0]._v;

    for (int i = 1; i < M; ++i) {
        for (int j = T - arr[i]._t; j > -1; --j) {
            if (dp[j] != -1) {
                dp[j + arr[i]._t] = max(dp[j] + arr[i]._v, dp[j + arr[i]._t]);
            }
        }
    }
    // for (int j = 0; j <= T; ++j) {
    //     cout << dp[j] << " ";
    // }
    // cout << endl;

    int Max = -999;
    for (int j = T; j > -1; --j) {
        if (dp[j] > Max) Max = dp[j];
    }
    cout << Max << endl;

    return 0;
}
