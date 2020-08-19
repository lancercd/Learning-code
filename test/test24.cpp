#include "iostream"
#include "algorithm"
#include "queue"
#include "utility"
#include "string.h"
using namespace std;

const int MAXN = 5e2 + 5;
int arr[MAXN][MAXN],vis[MAXN][MAXN];
int _dx[] = {1, -1, 0, 0}, _dy[] = {0,  0, 1, -1};
int N,M,end_x,end_y;


bool dfs(int _x, int _y){
    queue<pair<int, int> > que;
    que.push({_x,_y});
    while(!que.empty())
    {
        pair<int, int> now = que.front(); que.pop();
        int x = now.first, y = now.second;
        for(int i=0; i<4; ++i)
        {
            int dx = x + _dx[i];
            int dy = y + _dy[i];
            if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
            if(arr[dx][dy] == 0) continue;
            if(vis[dx][dy] != 0) continue;
            if(end_x == dx && end_y == dy){ return 1; }

            vis[dx][dy] = vis[x][y] + 1;
            que.push({dx, dy});
        }
    }
    return 0;
}
int main() {
    int start_x,start_y;char ch;
    while(scanf("%d%d", &N, &M) != EOF)
    {
        memset(arr, 0, sizeof(arr));
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<N; ++i)
            for(int j=0; j<M; ++j)
            {
                scanf(" %c", &ch);
                if(ch == 'S'){
                    start_x = i; start_y = j;
                    arr[i][j] = 1;
                }
                if(ch == 'E'){
                    end_x = i;end_y = j;
                    arr[i][j] = 1;
                }
                if(ch == '.') arr[i][j] = 1;
            }

        if (dfs(start_x, start_y)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
