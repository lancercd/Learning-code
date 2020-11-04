#include "algorithm"
#include "cstdio"
#include "iostream"

using namespace std;

typedef long long ll;

const int MAXN = 200005;
struct node
{
  ll weight, value;
} arr[MAXN];

bool cmp(const node x, const node y)
{
  return x.value * y.weight > x.weight * y.value;
}

ll dp[405];
int N, M;
void solve()
{
  for (int i = 1; i <= N; i++)
    scanf("%lld%lld", &arr[i].weight, &arr[i].value);
  sort(arr + 1, arr + N + 1, cmp);
  int i;
  ll ans = 0;
  for (i = 1; i <= N && M > 400; i++)
  {
    ans += arr[i].value;
    M -= arr[i].weight;
  }
  for (int i = 0; i <= M; i++)
    dp[i] = 0;
  for (int id = i; id <= N; id++)
  {
    for (int j = M; j >= arr[id].weight; j--)
      dp[j] = max(dp[j], dp[j - arr[id].weight] + arr[id].value);
  }
  printf("%lld\n", dp[M] + ans);
}
int main()
{
  freopen("../data/in.txt", "r", stdin);
  freopen("../data/out.txt", "w", stdout);
  while (~scanf("%d%d", &N, &M))
    solve();
  return 0;
}
