#include "iostream"
#include "algorithm"
#include "cmath"
using namespace std;
const int MAXN = 6e5 + 5;
int arr[MAXN];
int n, a, b;
bool todo(int max_time) {
    int count_time = 0, std_dry = a * max_time;
    for (int i=0; i < n; ++i) {
        if (arr[i] > std_dry) { count_time += ceil((arr[i] - std_dry) / (double)b); }
    }
    return count_time <= max_time;
}

int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(0);
    int i = 0, l = 0, r = 0, mid = 0; cin >> n >> a >> b;
    for (i = 0; i < n; ++i)
    {
        cin >> arr[i];
        if (r < arr[i]) r = arr[i];
    }
    while (l <= r) {
        mid = (l + r) >> 1;
        todo(mid) ? r = mid - 1 : l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
