#include "iostream"
#include "algorithm"
#include "climits"

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 205;
int arr[MAXN], dp[MAXN];

int main()
{
    register int i = 0,k = 0;int n; cin >> n;fill(dp, dp+n + 1, INF);
    for (int i = 1; i <= n; i++){cin >> arr[i];}
    dp[1] = 0;
    for (i = 2; i <= n; i++){
        if (arr[i] == arr[i - 1] + 1) dp[i] = min(dp[i], dp[i - 1] + 1);
        for (k = 1; k < i; k++){
            int jump = 1 << k,level = i - k;
            while (level < n && arr[level + 1] <= arr[i - k] + jump) level++;
            dp[level] = min(dp[level], dp[i] + k + 1);
        }
    }
    (dp[n] >= INF)? cout << -1:cout << dp[n];
    return 0;
}
