#include "iostream"
#include "algorithm"
#include "map"
typedef long long ll;
const int MAXN = 2e5 + 10;
int arr[MAXN];
int N, C;
std::map<int, int> map;
int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    std::cin >> N >> C;
    for(int i=0; i<N; ++i){
        std::cin >> arr[i];
        map[arr[i]]++;
        arr[i] -= C;
    }
    ll ans = 0;
    for(int i = 0;  i < N; ++i){
        ans += map[arr[i]];
    }
    std::cout << ans << std::endl;
    return 0;
}
