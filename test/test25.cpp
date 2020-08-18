#include <iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
const int maxlength = 505;
int a[maxlength][maxlength];

int selected[4][2] = { 1,0,-1,0,0,1,0,-1 };
int N, M, S, E;
queue<int>q;
bool bfs(int S)
{
    while (!q.empty()) q.pop();
    q.push(S);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        int x = temp / M ;
        int y = temp % M;
        for (int i = 0; i <= 3; i++)
        {
            int dx = x + selected[i][0];
            int dy = y + selected[i][1];
            if (dx<0 || dy<0 || dx>=N || dy>=M) continue;
            if (a[dx][dy] < 1)continue;
            if (dx * M + dy == E) return true;
            a[dx][dy] = 1;
            q.push(dx * M + dy);

        }
    }
    return false;
}
int main()
{
    while (scanf("%d%d", &N,&M) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(dis, 0, sizeof(dis));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                char c;
                scanf(" %c", &c);
                if (c == 'S') {
                    S = i  * M + j;
                    a[i][j] = -1;
                }
                if (c == 'E') {
                    E = M * i  + j;
                    a[i][j] = 3;
                }
                if (c == '.')  a[i][j] = 1;
            }

        if (bfs(S)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
