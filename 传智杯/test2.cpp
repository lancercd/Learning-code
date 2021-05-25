#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 10;
int n, k;
ll arr[MAXN] = {0};
int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> n >> k;
    for(int i=0; i<n; ++i) cin >> arr[i];
    if(k == 0 || n ==0){
        cout << 0;
        return 0;
    }
    int ans = 0;

    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j){
            if((arr[i] * arr[j]) <= k){
                ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}
