#include "iostream"
#include "algorithm"
#include "cstdio"

typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 2e1 + 10;

int ma[9][2] = {{-2,-1}, {-2, 1}, {-1,-2}, {-1,2}, {0,0}, {1,-2}, {1,2}, {2,-1}, {2,1}};
int step[2][2] = {{1, 0}, {0, 1}};

bool arr[MAXN][MAXN] = {0};
ull dp[MAXN][MAXN] = {0};
int end_x, end_y;



int main() {
    std::cin >> end_x >> end_y;
    end_x += 2; end_y += 2;
    int ma_x, ma_y;
    std::cin >> ma_x >> ma_y;
    ma_x += 2; ma_y += 2;
    for(int i=0; i<9; ++i)
    {
        arr[ma_x + ma[i][0]][ma_y + ma[i][1]] = 1;
    }
    dp[2][2] = 1;

    for(int i=2; i<=end_x; ++i){
        for(int j=2; j<=end_y; ++j)
        {
            if(arr[i][j]) continue;
            dp[i][j] = std::max(dp[i][j], dp[i][j-1] + dp[i-1][j]);
        }
    }

    std::cout << dp[end_x][end_y] << std::endl;

    return 0;
}
