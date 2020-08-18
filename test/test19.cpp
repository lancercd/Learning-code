#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
struct node
{
    int x, y, t;
    node(int x, int y, int t) : x(x), y(y), t(t) {}
};
int vis[305][1005], g[305][305];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int bfs()
{
    queue<node> q;
    q.push(node(0, 0, 0));
    vis[0][0] = 1;
    while (!q.empty())
    {
        node u = q.front();
        q.pop();
        if (g[u.x][u.y] == 0x3f3f3f3f)
        {
            return u.t;
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = u.x + dx[i];
            int ty = u.y + dy[i];
            if (tx < 0 || ty < 0 || vis[tx][ty])
                continue;
            if (u.t + 1 >= g[tx][ty])
                continue;
            vis[tx][ty] = 1;
            q.push(node(tx, ty, u.t + 1));
        }
    }
}
int main()
{
    int m, x, y, t;
    cin >> m;
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> t;
        g[x][y] = min(t, g[x][y]);
        for (int j = 0; j < 4; j++)
        {
            int tx = x + dx[j];
            int ty = y + dy[j];
            if (tx < 0 || ty < 0)
                continue;
            g[tx][ty] = min(g[tx][ty], t);
        }
    }
    cout << bfs() << endl;
}
