#include "iostream"
#include "algorithm"

using namespace std;
const int MAXN = 5e6 + 10;
int arr[MAXN];
int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);cout.tie(0);
    int N, k; cin >> N >> k;
    for(int i=0; i<N; ++i) {cin >> arr[i];}
    nth_element(arr, arr + k, arr + N);
    cout << arr[k] << endl;
    return 0;
}
