#include "iostream"
#include "algorithm"

//洛谷  P1048 采药  (0/1背包问题)

using namespace std;
const int MAXN = 1e3 + 5;
int T, M;
int spend[MAXN]  = {0};
int value[MAXN] = {0};
int dp[1005]   = {0};



int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> T >> M;
    for(int i=0; i<M; ++i)
    {
        cin >> spend[i] >> value[i];
    }

    dp[spend[0]] = value[0];

    for(int i=1; i<M; ++i)
    {
        for(int j=T; j > 0; --j){
            if(dp[j] != 0){
                dp[j + spend[i]] = max(dp[j] + value[i], dp[j + spend[i]]);
            }
        }
        dp[spend[i]] = max(dp[spend[i]], value[i]);
    }
    cout << *max_element(dp + 1, dp + T + 1);
    return 0;
}
