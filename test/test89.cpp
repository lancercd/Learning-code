#include "iostream"
#include "algorithm"
typedef long long ll;
using namespace std;


const int MAXN = 1e5 + 10;
int arr[MAXN] = {0};
int N;
int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    cin >> N;
    for(int i = 0;  i < N; ++i){
        cin >> arr[i];
    }
    ll sum = 0;
    for(int i = 1;  i < N; ++i){
        sum += arr[i] - arr[i-1];
    }
    ll ans = arr[N-1] + (sum / (N-1));
    cout << ans << endl;
    return 0;
}
