#include "iostream"
#include "queue"
#include "algorithm"
#include "cstring"
#include "climits"

using namespace std;
const int MAXN = 1e3 + 5;
int arr[MAXN][MAXN] = {0}, vis[MAXN][MAXN] = {0};
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int N,M,R,C;

int bfs(bool type){

    queue<pair<int, int> > que;
    que.push({0,0});
    while(que.size())
    {
        pair<int,int> now = que.front(); que.pop();
        int x = now.first, y = now.second;
        for(int i=0; i<4; ++i)
        {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx < 0 || dy < 0 || dx > N || dy > M) continue;
            if(vis[dx][dy] != 0) continue;  //不等于0 走过了
            if(arr[dx][dy] == 0) continue;
            if(type){
                if(arr[dx][dy] == 2) continue;
            }else {
                if(arr[dx][dy] == 3) continue;
            }
            if(dx == R && dx == C){return vis[x][y] - 1;};
            vis[dx][dy] = vis[x][y] + 1;
            que.push({dx,dy});
        }
    }
    for(int i=0; i< N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cout << vis[i][j] << " ";
        }
        cout<< endl;
    }
    return INT_MAX;
}


int main(int argc, char const *argv[]) {
    int T; cin >> T;
    while(T--)
    {
        memset(arr, 0, sizeof(arr));
        memset(vis, 0, sizeof(vis));vis[0][0] = 1;
        char ch; cin >>N >> M >> R >>C;  R-=1; C-=1;
        for(int i=0; i<N; ++i){
             for(int j=0; j<M; ++j){
                cin >> ch;
                if(ch == '.') arr[i][j] = 1;
                else if(ch == 'F') arr[i][j] = 2;
                else if(ch == 'M') arr[i][j] = 3;
             }
        }
        // for(int i=0; i<N; ++i){
        //     for(int j=0; j<M; ++j){
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int ans1 = bfs(true);
        memset(vis, 0, sizeof(vis));vis[0][0] = 1;
        int ans2 = bfs(false);

        int ans = min(ans1, ans2);
        (ans == INT_MAX)? cout<< "IMPOSSIBLE" << endl: cout<< ans << endl;


    }

    return 0;
}
