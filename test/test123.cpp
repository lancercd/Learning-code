#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;
const int MAXN = 505;
int N, M;
typedef struct{int p,q,v;}Node;
Node arr[MAXN];

int dp[MAXN][5005];

bool cmp(Node a, Node b){
    return a.q < b.q;
}

int main()
{
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        fill(dp[0], dp[0] + (N + 2) * (M + 2), 0);
        for(int i=1;i<=N;i++){scanf("%d%d%d",&arr[i].p, &arr[i].q, &arr[i].v);}
        sort(arr, arr + N + 1, cmp);
        for(int i=1; i<=N; ++i)
        {
            for(int j=1; j <= M; ++j)
            {
                //不买 或 买不起
                if(arr[i].q > j || arr[i].p > j){
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
                // 买和不买 中选一个价值最大的
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - arr[i].p] + arr[i].v);

            }
        }
        for(int i=0; i<=N; ++i)
        {
            for(int j=0; j <= M; ++j)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        printf("%d\n",dp[N][M]);
    }

    return 0;
}
