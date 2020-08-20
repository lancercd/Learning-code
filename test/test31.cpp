#include "iostream"
#include "algorithm"
using namespace std;
const int MAXN = 30;
// int arr[MAXN][MAXN] = {0};
long long dp[MAXN][MAXN] = {0};

int mdir[8][2] = { {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2} };
int ex,ey,x2,y2;

int main(int argc, char const *argv[]) {
    cin >> ex >> ey >> x2 >> y2;
    dp[0][0] = 1; dp[x2][y2] = -1;
    for(int i=0; i<9; ++i){
        int dx = x2 + mdir[i][0];
        int dy = y2 + mdir[i][1];
        if(dx <0 || dy < 0 || dx > ex || dy > ey) continue;
        dp[dx][dy] = -1;
    }
    for(int i=0; i <= ex; ++i){
        for(int j=0; j <= ey; ++j){
            if(dp[i][j] == -1) continue;
            if(dp[i + 1][j] != -1) dp[i + 1][j] += dp[i][j];
            if(dp[i][j + 1] != -1) dp[i][j + 1] += dp[i][j];
        }
    }
    // for(int i=0; i <= ex; ++i)
    // {
    //     for(int j=0; j <= ey; ++j)
    //     {
    //         printf("%2d ", dp[i][j]);
    //     }
    //     cout << endl;
    // }
    // cout << "dp" << endl;
    // for(int i=0; i <= ex; ++i)
    // {
    //     for(int j=0; j <= ey; ++j)
    //     {
    //         if(dp[i][j] == -1){
    //             printf(" * ");
    //         }else{
    //             printf("%2d ", dp[i][j]);
    //         }
    //     }
    //     cout << endl;
    // }

    cout << dp[ex][ey] << endl;
    return 0;
}
