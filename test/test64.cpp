#include "iostream"
#include "algorithm"

using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 10;
ll arr[MAXN] = {0};
ll N, M, Max;

bool check(ll target){
    ll count = 0;
    for(int i=0; i<N; ++i)
    {
        if(arr[i] <= target) continue;
        count += arr[i] - target;
    }
    return count >= M;
}

ll binarySearch()
{
    ll ans = -1,left = 0, right = Max;
    while(left <= right)
    {
        ll mid = (left + right) >> 1;
        if(check(mid)){
            ans = mid;
            left = mid + 1;
        }else right = mid - 1;

    }
    return ans;
}


int main() {
    cin >> N >> M;
    for(int i=0; i<N; ++i) {cin >> arr[i]; Max = max(Max, arr[i]);}
    if(M ==0){ cout << 0; return 0;}

    cout << binarySearch() << endl;
    return 0;
}
