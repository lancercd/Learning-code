#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

const int N = 101;
const int M = 101;
bool arr[N][M] = {0};
int n, m;
int ans = 0;

int _x[] = {-1, 0, 0, 1};
int _y[] = { 0, -1, 1, 0};



void dfs(int x, int y){
    arr[x][y] = 0;
    for(int i=0; i<4; ++i)
    {
        int cur_x = x + _x[i];
        int cur_y = y + _y[i];
        if(cur_x > -1 && cur_y > -1 && cur_x < n && cur_y < m && arr[cur_x][cur_y]){
            dfs(cur_x, cur_y);
        }

    }
}




int main(){
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> n >> m;
    char tmp;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j)
        {
            cin >>tmp;
            arr[i][j] = (tmp != '0');
        }
    }

    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            if(arr[i][j]){
                ++ans;
                dfs(i, j);
            }

    cout << ans << endl;
    return 0;
}
