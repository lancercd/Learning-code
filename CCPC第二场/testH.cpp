#include "iostream"
#include "cstring"

#define ll long long
using namespace std;
const ll MAXN=2e5 + 10;
ll N,M,dp[MAXN];
ll weight[MAXN];
ll value[MAXN];
inline ll read()
{
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-')f = -1;ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}
    return x * f;
}


int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    while(scanf("%lld%lld", &N, &M) != EOF){
        memset(dp, 0, sizeof(dp));
        int i, tmp;
        for(i=1;i<=N;i++){
            weight[i] = read(); value[i] = read();
        }

        for(i=1;i<=N;i++)
            for(int j=M;j>=1;j--)
            {
                tmp = j-weight[i];
                if(dp[j]<=dp[tmp]+value[i] && tmp>=0 )
                     dp[j]=dp[tmp]+value[i];
            }
        printf("%lld\n", dp[M]);
    }

}
