#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;
const int MAXN = 505;
int N, M;
typedef struct{int p,q,v;}Node;
Node arr[MAXN];

int dp[5005];
bool cmp(Node a,Node b)
{
    return a.q - a.p <= b.q - b.p;
}
int main()
{
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        fill(dp, dp + M + 1, 0);
        for(int i=0;i<N;i++){scanf("%d%d%d",&arr[i].p, &arr[i].q, &arr[i].v);}
        sort(arr, arr+N, cmp);
        for(int i=0; i<N; i++)
        {
            for(int j=M; j >= arr[i].q; j--)
                dp[j]=max(dp[j], dp[j - arr[i].p] + arr[i].v);
        }
        printf("%d\n",dp[M]);
    }

    return 0;
}
