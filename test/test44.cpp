#include "iostream"
#include "algorithm"
#include "queue"
using namespace std;
int N, M;
const int MAXN = 1e2 + 5;
int arr[MAXN][MAXN] = {0};
// int vis[MAXN][MAXN] = {0};
int _dx[] = {-1, 1, 0, 0};
int _dy[] = {0, 0, -1, 1};

int dfs(){
    queue<pair<int, int > > que;
    que.push({0, 0}); arr[0][0] = 1;
    while(que.size()){
        pair<int , int> now = que.front(); que.pop();

        for(int i=0; i<4; ++i)
        {
            int dx = now.first + _dx[i];
            int dy = now.second + _dy[i];
            if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
            if(arr[dx][dy] == 999) return 1;
            if(arr[dx][dy] != 0) continue;
            arr[dx][dy] = 1;
            que.push({dx, dy});
        }
    }


    return 0;
}

int main(int argc, char const *argv[]) {
    cin >> N >> M;
    for(int i=0; i< N; ++i){
        for(int j=0 ; j<M; ++j){
            cin >> arr[i][j];
        }
    }
    arr[N-1][M-1] = 999;
    int ans = dfs();
    // for(int i=0; i< N; ++i){
    //     for(int j=0 ; j<M; ++j){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ans? cout << "YES": cout << "NO";
    return 0;
}
