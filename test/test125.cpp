#include "iostream"
#include "algorithm"

//洛谷  P1048 采药  (0/1背包问题)   非空间压缩

using namespace std;
const int MAXN = 1e3 + 5;
int T, M;
int spend[MAXN]  = {0};
int value[MAXN] = {0};
int dp[1005][1005]   = {0};



int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> T >> M;
    for(int i=1; i<=M; ++i)
    {
        cin >> spend[i] >> value[i];
    }

    for(int i=1; i<=M; ++i)
    {
        for(int j=1; j <= T; ++j){
            //装不下
            if(j < spend[i]){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i-1][j - spend[i]] + value[i]);
        }
    }

    // for(int i=0; i<=M; ++i)
    // {
    //     for(int j=0; j <= T; ++j){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    cout << dp[M][T] << endl;
    return 0;
}
