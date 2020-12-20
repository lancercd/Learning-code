#include "iostream"
#include "algorithm"
#include "vector"

typedef long long ll;
using namespace std;

ll N, V, M, A;

int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N >> V >> M >> A;

    ll ans = 0;
    int t=1;
    for(int i=0; i<N; ++i){
        if(t == M){
            t = 1;
            ans += V;
            V += A;
            continue;
        }
        ans += V;
        ++t;
    }

    cout << ans;

    return 0;
}
