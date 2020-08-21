#include "iostream"
#include "algorithm"
#include "string"
using namespace std;
const  int  MAXN = 1e3 + 5;
int dp[MAXN][MAXN] = {0};
int main(int argc, char const *argv[]) {
    int N,M;string a,b; cin >> N >> M >> a >> b;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(a[i] == b[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
            // if(a[i] == b[j]) dp[i + 1][j + 1] = max(dp[i][j+1], dp[i+1][j]) + 1;
            else dp[i + 1][j + 1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }

    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<M; ++j){
    //         cout << dp[i + 1][j + 1] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[N][M] << endl;




    return 0;
}
