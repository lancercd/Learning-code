#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
typedef long long ll;
const int MAX_N = 1e4 + 5, MAX_T = 1e7 + 5;
typedef struct node {
    ll t, v;
}Node;
Node arr[MAX_N];
ll M, T, dp[MAX_T] = { 0 };

int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> T >> M;
    for (int i = 1; i <= M; ++i) cin >> arr[i].t >> arr[i].v;

    for (int i = 1; i <= M; ++i) {
        for (int j = arr[i].t; j <= T; ++j) {
            dp[j] = max(dp[j], dp[j - arr[i].t] + arr[i].v);
        }
    }
    cout << dp[T];
    return 0;
}
