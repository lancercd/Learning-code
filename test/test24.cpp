//牛客  [走出迷宫]
//还没过   显示超出内存
#include "iostream"
#include "algorithm"
#include "queue"
#include "utility"
#include "string.h"
using namespace std;

const int MAXN = 5e2 + 5;
int arr[MAXN][MAXN], dx[] = {1, -1, 0, 0}, dy[] = {0,  0, 1, -1},n,m;
queue<pair<int, int> > que;

bool dfs(int x, int y){
    while(que.size()) que.pop();
    arr[x][y] = -1;
    que.push({x,y});
    while(que.size())
    {
        pair<int, int> now = que.front(); que.pop();
        for(int i=0; i<4; ++i)
        {
            int xx = now.first + dx[i], yy = now.second + dy[i];
            if(xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
            if(arr[xx][yy] < 1) continue;

            if(arr[xx][yy] == 3){ return 1; }
            arr[xx][yy] = -1;
            // vis[xx][yy] = 1;
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
                     if(ch == 'S'){start_x = j; start_y = i; arr[i][j] = 1;}
                else if(ch == '.'){arr[i][j] = 1;}
                else if(ch == '#'){arr[i][j] = 0;}
                else if(ch == 'E'){arr[i][j] = 3;}
            }
        }
        dfs(start_x, start_y)? cout << "yes" << endl: cout << "No" << endl;
    }


    return 0;
}
