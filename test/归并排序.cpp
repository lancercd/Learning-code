#include <iostream>
using namespace std;
typedef long long ll;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAX = 1e5 + 7;
int n, info[MAX], tmp[MAX];
ll ans;

void merge(int l, int mid, int r);
void merge_sort(int l, int r);

int main() {
    IOS;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> info[i];
    merge_sort(1, n);
    cout << ans << endl;
    return 0;
}
void merge_sort(int l, int r) {
    if (l == r) return;
    int mid = l + r >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, mid, r);
}
void merge(int l, int mid, int r) {
    int x = l, y = mid + 1;
    int pos = 1;
    while (x <= mid && y <= r) {
        if (info[x] > info[y]) {
            tmp[pos++] = info[y++];
            ans += mid - x + 1;
        }
        else tmp[pos++] = info[x++];
    }
    while (x <= mid) tmp[pos++] = info[x++];
    while (y <= r) tmp[pos++] = info[y++];
    for (int i = r; i >= l; i--) info[i] = tmp[--pos];
}
