#include "iostream"
#include "algorithm"

using namespace std;
const int MAXN = 1e7 + 5;
int dp[MAXN];
int arr[MAXN];
int N;
int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N;
    int tmp, LEN = 0, ans = 0;
    while(N--){
        cin >> tmp;
        LEN = max(LEN, tmp);
        ++arr[tmp];
    }
    ++LEN;
    for(int i=LEN; i > 1; --i)
    {
        if(!arr[i]) continue;
        for(int j=i<<1; j<LEN; j += i){
            dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += arr[i];
        ans = max(dp[i], ans);
    }
    if(arr[1]) ans += arr[1];
    cout << ans << endl;
    return 0;
}
