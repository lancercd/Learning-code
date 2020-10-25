#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
// typedef unsigned long long ull;
const int MOD = 998244353;

int N, M;

int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N >> M;
    if(N == 0 || M == 0){
        cout << 0 << endl;
        return 0;
    }
    int ans = 1;
    for(int i=0; i<M; ++i)
    {
        ans = (ans * (N-i)) % MOD;
    }
    cout << ans;
    return 0;
}
