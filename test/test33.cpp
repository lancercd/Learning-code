#include "iostream"
#include "algorithm"

using namespace std;

const int MAXN = 35;
int dp[MAXN][MAXN] = {0};

int main(int argc, char const *argv[]) {
    int N,M; cin >> N >> M;dp[0][0] = 1;
    for(int i=0; i<M; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=1; i<M; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            if(j == 0) dp[i][0] = dp[i-1][1] + dp[i-1][N-1];
            if(j == (N-1)) dp[i][j] = dp[i-1][0] + dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j + 1] + dp[i-1][j-1];
        }
    }
    for(int i=0; i<M; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
