#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

int dp[10005];
int main()
{
    freopen("../../data/in.txt", "r", stdin); freopen("../../data/out.txt", "w", stdout);
    int n, a, b, c;
    cin>> n >> a >> b >> c;
    for(int i=0; i<=n; i++){
        if(i==0 || dp[i]){
        dp[i+a]=max(dp[i+a], dp[i]+1);
        dp[i+b]=max(dp[i+b], dp[i]+1);
        dp[i+c]=max(dp[i+c], dp[i]+1);
        }
    }
    printf("%d\n", max(dp[n], 1));
    return 0;
}
