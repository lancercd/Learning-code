#include "iostream"
#include "algorithm"

using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 10;
int arr[MAXN] = {0};
int N, M;

bool check(int target){
    ll count = 0;
    for(int i=0; i < N; ++i){
        if(arr[i] <= target) continue;
        count += arr[i] - target;
    }
    return count > M;
}

int binarySearch(){
    int l = 0, r = M;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid;
    }

    return l;
}

int main() {
    cin >> N >> M;
    for(int i=0; i<N; ++i) cin >> arr[i];
    if(M ==0){ cout << 0; return 0;}

    cout << binarySearch() << endl;
    return 0;
}
