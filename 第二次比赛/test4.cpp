#include "iostream"
#include "algorithm"
#include "queue"

using namespace std;
int arr[305][305] = { 0 }, vis[305][305] = { 0 }, n;
int dis_x[] = { -1,  0, 0, 1 }, dis_y[] = { 0, -1, 1, 0 };
typedef struct node { int x, y, t; node(int x, int y, int t) : x(x), y(y), t(t) {}; }Node;
queue<Node> que;

void modify(int x, int y, int t) {
    arr[x][y] = min(arr[x][y], t);
    for (int i = 0; i < 4; ++i) {
        int tx = x + dis_x[i], ty = y + dis_y[i];
        if(tx < 0 || ty < 0) continue;
        arr[tx][ty] = min(arr[tx][ty], t);
    }
}

int dfs() {
    que.push({0, 0, 0}); vis[0][0] = 1;

    while (que.size()) {
        node cur = que.front(); que.pop();
        if (arr[cur.x][cur.y] == 1001) return cur.t;
        for (int i = 0; i < 4; ++i) {
            int x = dis_x[i] + cur.x;
            int y = dis_y[i] + cur.y;
            int t = cur.t + 1;
            if (x < 0 || y < 0 || vis[x][y]) continue;
            if(t >= arr[x][y]) continue;
            vis[x][y] = 1;
            que.push({x, y, t});
        }
    }
}

int main() {
    int i, x, y, t;
    cin >> n;
    for(i=0; i<305; ++i) fill(arr[i], arr[i] + 305, 1001);

    for (i = 0; i < n; ++i) {
        cin >> x >> y >> t;
        modify(x, y, t);
    }
    // for(i=0; i<10; ++i){
    //     for(int j=0; j<10; ++j){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dfs() << endl;
    return 0;
}
