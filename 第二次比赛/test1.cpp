#include "iostream"
#include "algorithm"
#include "climits"
//INF const int INF = 0x3f3f3f3f;
using namespace std;
const int MAXN = 205;
int arr[MAXN], dp[MAXN];

int main() {
    fill(dp, dp + MAXN, INT_MAX); dp[0] = 0;

    register int i = 0, k = 0; int N; cin >> N; for (; i < N; ++i) cin >> arr[i];

    for (i = 1; i < N; ++i)
    {
        if (arr[i] - arr[i - 1] == 1) dp[i] = min(dp[i], dp[i - 1] + 1);

        for (k = 1; k < i; ++k)
        {
            // int level = i - k, hight = (k << 1) + arr[level];
            // while ((hight < arr[level]) && level < N) { ++level; }
            // dp[level] = min(dp[level], dp[i] + k + 1);

            int jump = 1 << k; //能跳多少级
            int maxh = i - k; //后退之后的级数
            while (maxh < N && arr[maxh + 1] <= arr[i - k] + jump) {  // 找到能到的最高阶梯
                maxh++;
            }
            dp[maxh] = min(dp[maxh], dp[i] + k + 1);
        }
    }
    for (i = 0; i <= N; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;

    (dp[N - 1] = INT_MAX) ? cout << -1 : cout << dp[N - 1];


    return 0;
}
