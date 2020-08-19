#include <iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
const int MAXN = 505;
int a[MAXN][MAXN];
int vis[MAXN][MAXN];
int _dx[] = {1, -1, 0, 0}, _dy[] = {0,  0, 1, -1};
int N, M, start_x,start_y, end_x,end_y;

bool bfs(int _x, int _y)
{
    queue<pair<int, int>> q;
    q.push({_x, _y});
    while (!q.empty())
    {
        pair<int,int> temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;
        for (int i = 0; i < 4; i++)
        {
            int dx = x + _dx[i];
            int dy = y + _dy[i];
            if (dx<0 || dy<0 || dx>=N || dy>=M) continue;
            if (a[dx][dy] == 0)continue;
            if (vis[dx][dy] != 0) continue;
            if (dx== end_x && dy == end_y) return true;
            vis[dx][dy] = vis[x][y] + 1;
            q.push({dx, dy});

        }
    }
    return false;
}
int main()
{
    while (scanf("%d%d", &N,&M) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                char c;
                scanf(" %c", &c);
                if (c == 'S') {
                    start_x = i; start_y = j;
                    a[i][j] = 1;
                }
                if (c == 'E') {
                    end_x = i;end_y = j;
                    a[i][j] = 1;
                }
                if (c == '.')  a[i][j] = 1;
            }

        if (bfs(start_x, start_y)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
