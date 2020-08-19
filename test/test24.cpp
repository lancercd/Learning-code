
#include "iostream"
#include "algorithm"
#include "queue"
#include "utility"
#include "string.h"
using namespace std;

const int MAXN = 5e2 + 5;
int arr[MAXN][MAXN],vis[MAXN][MAXN];
int dx[] = {1, -1, 0, 0}, dy[] = {0,  0, 1, -1};
int n,m,end_x,end_y;


bool dfs(int _x, int _y){
    queue<pair<int, int> > que;
    que.push({_x,_y});
    while(!que.empty())
    {
        pair<int, int> now = que.front(); que.pop();
        for(int i=0; i<4; ++i)
        {
            int xx = now.first + dx[i], yy = now.second + dy[i];
            if(xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
            if(arr[xx][yy] == 0) continue;
            if(vis[xx][yy] != 0) continue;
            if(end_x == xx && end_y == yy){ return 1; }

            vis[xx][xx] = vis[now.first][now.second] + 1;
            que.push({xx, yy});
        }
    }
    return 0;
}
int main() {
    int i,j, start_x,start_y;char ch;
    while(cin >> n >> m)
    {
        // fill(arr[0], arr[0] + (m+1) * (n+1), 0);
        memset(arr, 0, sizeof(arr));
        for(i=0; i<n; ++i)
        {
            for(j=0; j<m; ++j)
            {
                cin >> ch;
                     if(ch == 'S'){start_x = i; start_y = j; arr[i][j] = 1;}
                else if(ch == '.'){arr[i][j] = 1;}
                else if(ch == 'E'){arr[i][j] = 1; end_x = i;end_y = j;}
            }
        }
        dfs(start_x, start_y)? cout << "yes" << endl: cout << "No" << endl;
    }


    return 0;
}
