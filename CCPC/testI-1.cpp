#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;

const int MAXN = 1e3 + 10;

int N, M;
char box[MAXN][MAXN];
int arr[MAXN][MAXN];

int dfs(int x, int y){
    if(arr[x][y] != -1) return arr[x][y];
    if(x<1 || y<1 || x>N || y>M) return 1;
    arr[x][y] = 0;
    if(box[x][y] == 'W') arr[x][y] = dfs(x-1, y);
    if(box[x][y] == 'A') arr[x][y] = dfs(x, y-1);
    if(box[x][y] == 'S') arr[x][y] = dfs(x+1, y);
    if(box[x][y] == 'D') arr[x][y] = dfs(x, y+1);

    return arr[x][y];
}

int main(){
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    scanf("%d%d",&N,&M);
    for(int i=1; i<=N; ++i) scanf("%s",box[i] + 1);
    memset(arr,-1,sizeof(arr));
    int ans=0;
    for(int i=1; i<=N; ++i) for(int j=1; j<=M; ++j)
        if (dfs(i,j)) ++ans;
    cout<<ans<<endl;
}
