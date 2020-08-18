#include "iostream"
#include "cstdio"
using namespace std;

typedef struct { int x,y; }Node;
Node c, b;

int ma_x[] = {-2, -2, -1, -1, 0,  1, 1,  2, 2};
int ma_y[] = {-1,  1, -2,  2, 0, -2, 2, -1, 1};
bool ma[30][30] = {0};
unsigned long long dp[30][30] = {0};

int main(int argc, char const *argv[]) {
    cin >> b.x >> b.y >> c.x >> c.y;
    b.x += 2; b.y += 2; c.x += 2; c.y += 2;
    ma[c.x][c.y] = 1;
    for(int i=0; i<9; ++i){ ma[c.x + ma_x[i]][c.y + ma_y[i]] = 1;}
    dp[2][2] = 1;
    // dp[3][2] = 1;
    // dp[2][3] = 1;
    for(int i=2; i <= b.x; ++i){
        for(int j=2; j<= b.y; ++j){
            if(ma[i][j]) continue;
            dp[i][j] = max(dp[i][j], dp[i-1][j] + dp[i][j-1]);
        }
    }
    // for(int i=0; i < 24; ++i){
    //     for(int j=0; j < 24; ++j){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[b.x][b.y] << endl;
    return 0;
}
