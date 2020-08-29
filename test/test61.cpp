#include "iostream"
#include "algorithm"
#include "climits"

using namespace std;
typedef unsigned long long ull;
const int MAXN = 5e4 + 10;
int arr[MAXN] = { 0 };
int M, N, L;

bool judge(int x){
    int tot = 0, i = 0, now = 0;
    while (i < N + 1){
        i++;
        if (arr[i] - arr[now] < x)
            tot++;
        else
            now = i;
    }
    if (tot > M)
        return false;
    else
        return true;
}
int main() {
    cin >> L >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    arr[N + 1] = L;

    int l = 1, r = L, ans;
    while (l <= r) {
        int  mid = (l + r) >> 1;
        if (judge(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }


    cout << ans << endl;
    return 0;
}
