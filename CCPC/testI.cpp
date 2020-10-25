#include "iostream"
#include "algorithm"
#include "queue"
#include "utility"

using namespace std;
const int MAXN = 1e3 + 5;
char table[MAXN][MAXN] = { 0 };
// int arr[MAXN][MAXN] = { 0 };
int N, M;
int dir[4][2] = { {-1,0}, {0, -1}, {0, 1}, {1, 0} };


int dfs(int x, int y) {
    int cnt = 1;
    queue<pair<int, int> > que;
    que.push({ x, y });
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dx = cur.first + dir[i][0], dy = cur.second + dir[i][1];
            if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;

            if (i == 0) {
                if (table[dx][dy] == 'S') {
                    que.push({ dx, dy });
                    ++cnt;
                }
            }
            else if (i == 1) {
                if (table[dx][dy] == 'D') {
                    que.push({ dx, dy });
                    ++cnt;
                }
            }
            else if (i == 2) {
                if (table[dx][dy] == 'A') {
                    que.push({ dx, dy });
                    ++cnt;
                }
            }
            else if (i == 3) {
                if (table[dx][dy] == 'W') {
                    que.push({ dx, dy });
                    ++cnt;
                }
            }
        }
    }
    return cnt;
}


int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N >> M;
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> table[i][j];
        }
    }

    //边处理
    for (int i = 0; i < M; ++i)
    {
        if (table[0][i] == 'W') ans += dfs(0, i);
        if (table[N - 1][i] == 'S') ans += dfs(N - 1, i);
    }
    for (int i = 0; i < N; ++i)
    {
        if (table[i][0] == 'A') ans += dfs(i, 0);
        if (table[i][M - 1] == 'D') ans += dfs(i, M - 1);
    }
    // for (int i = 0; i < M; ++i)
    // {
    //     if (table[0][i] == 'W') arr[0][i] = dfs(0, i);
    //     if (table[N - 1][i] == 'S') arr[N - 1][i] = dfs(N - 1, i);
    // }
    // for (int i = 0; i < N; ++i)
    // {
    //     if (table[i][0] == 'A') arr[i][0] = dfs(i, 0);
    //     if (table[i][M - 1] == 'D') arr[i][M - 1] = dfs(i, M - 1);
    // }
    // for (int i = 0; i < M; ++i)
    // {
    //     if (table[0][i] == 'W') ans += arr[0][i];
    //     if (table[N - 1][i] == 'S') ans += arr[N - 1][i];
    // }
    // for (int i = 0; i < N; ++i)
    // {
    //     if (table[i][0] == 'A') ans += arr[i][0];
    //     if (table[i][M - 1] == 'D') ans += arr[i][M - 1];
    // }

    cout << ans << endl;




    // for (int i = 0; i < N; ++i)
    // {
    //     for (int j = 0; j < M; ++j)
    //     {
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }


    return 0;
}
