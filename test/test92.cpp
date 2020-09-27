#include "iostream"
#include "algorithm"

using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 10;
ll arr[MAXN][MAXN] = {0};
int N, M, C;
int X = 0, Y = 0;

int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    cin >> N >> M >> C;
    for(int i=1; i<=N; ++i)
    {
        for(int j=1; j<=M; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=1; i<=N; ++i)
    {
        for(int j=1; j<=M; ++j)
        {
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];

        }
    }

    ll Max = -9999;
    for(int i=C; i<=N; ++i)
    {
        for(int j=C; j<=M; ++j)
        {
            ll current = arr[i][j] - arr[i-C][j] - arr[i][j-C] + arr[i-C][j-C];
            if(Max < current)
            {
                X = i-C;
                Y = j-C;
                Max = current;
            }
        }
    }


    cout << X + 1 << " " << Y + 1;
    return 0;
}
