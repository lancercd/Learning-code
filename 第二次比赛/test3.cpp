#include "iostream"
#include "algorithm"
#include "climits"
using namespace std;
const int MAXN = 205;
int arr[MAXN], dp[MAXN], N;
int main(int argc, char const *argv[]) {
    int i=0; cin >> N; for(i=0; i<N; ++i) cin >> arr[i];
    fill(dp, dp + N + 1, 0x3f3f3f3f); dp[0] = 0;
    for(i=1; i<N; ++i)
    {
        if(arr[i] - arr[i-1] == 1) dp[i] = min(dp[i], dp[i-1] + 1);
        for(int k=1; k <= i; ++k){
            int height = arr[i-k] + (1 << k), to=i-k + 1;
            while(height >= arr[to] && to < N){
                dp[to] = min(dp[to], dp[i] + k + 1);
                ++to;
            }
        }
    }
    // for(i=0; i<N+2; ++i){ cout << dp[i] << " " ; }
    // cout << endl;
    (dp[N - 1] >= 0x3f3f3f3f)? cout << -1:cout << dp[N - 1];

    return 0;
}
