#include "iostream"
#include "algorithm"
#include "utility"
using namespace std;
typedef long long ll;
#define _v second
#define _w first
const int MAXN = 1e4 + 5;
pair<ll,ll> arr[105];
ll dp[MAXN];
int main(int argc, char const *argv[]) {
    int N,V; cin >> N >> V; for(int i=0; i<N; ++i) {cin >> arr[i]._w >> arr[i]._v;}

    fill(dp, dp + V + 2, -1); dp[0] = 0;
    // dp[arr[0]._w] = arr[0]._v;
    for(int i=0; i < N; ++i){
        for(int j = V - arr[i]._w; j > -1; --j){
            if(dp[j] != -1){
                int total_w = j + arr[i]._w;
                if(total_w > V) continue;
                dp[total_w] = max(dp[total_w], dp[j] + arr[i]._v);
            }
        }
    }


    // for(int i=0; i<=V; ++i){
    //     cout << dp[i] << " ";
    // }



    ll Max = -999;

    for(int i = V; i > -1; --i) if(dp[i] != -1 && dp[i] > Max) Max = dp[i];
    cout << Max << endl;
    return 0;
}
