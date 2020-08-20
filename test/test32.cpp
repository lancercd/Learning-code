#include "iostream"
#include "algorithm"
#define mem(a,b) memset(a,b,sizeof(a))

typedef long long ll;
using namespace std;
const int maxn = 2e5 + 10;

int dp[100][100];
int dir[10][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
int main() {

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    dp[x2][y2]=-1;
    for(int i=0;i<8;++i){
        int xx=x2+dir[i][0],yy=y2+dir[i][1];
        if(xx<0||yy<0||xx>x1||yy>y1)continue;
        dp[xx][yy]=-1;
    }
    dp[0][0] = 1;
    for(int i = 0; i <= x1; ++i) {
        for(int j = 0; j <= y1; ++j) {
            if(dp[i][j] != -1) {
                if(dp[i + 1][j] != -1)
                    dp[i + 1][j] += dp[i][j];
                if(dp[i][j + 1] != -1)
                    dp[i][j + 1] += dp[i][j];
            }
        }
    }
    for(int i = 0; i <= x1; ++i) {
        for(int j = 0; j <= y1; ++j) {
            printf("%2d ", dp[i][j]);
        }
        cout << endl;
    }
    cout<<dp[x1][y1]<<endl;


}
