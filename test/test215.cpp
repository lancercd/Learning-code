#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
const int MAXN = 1e3 + 3;
int arr[MAXN] = { 0 };
int dp[105][MAXN] = { 0 };
int N, M;
int dfs(int target, int mon) {
  if(mon == 0) return 1;
  if(target == N) return 0;
  int ans = 0;

  if(dp[target][mon] != -1) return dp[target][mon];

  ans += dfs(target + 1, mon);
  int res = mon - arr[target];
  if(res < 0){
    dp[target][mon] = ans;
    return ans;
  }

  ans += dfs(target + 1, res);

  dp[target][mon] = ans;

  return ans;
}

int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    fill(dp[0], dp[0] + (105 * MAXN), -1);
    cin >> N >> M;
    for(int i=0; i<N; ++i) cin >> arr[i];

    cout << dfs(0, M) << endl;
    return 0;
}
