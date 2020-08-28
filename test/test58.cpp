#include "iostream"
#include "algorithm"

using namespace std;
const int MAXN = 1e6 + 10, MAXM = 1e5 + 10;
int arr[MAXN], query[MAXM];
int N, M;
int myfind(int left, int right, int num) {
    if(left == right){
        if(arr[left] == num)
            return left;
        else
            return -1;
    }
    int mid = (left + right) >> 1;
    if(num <= arr[mid]) myfind(left, mid, num);
    else myfind(mid + 1, right, num);

}
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    for (int i = 1; i <= M; ++i) cin >> query[i];
    for (int i = 1; i <= M; ++i) {
        cout << myfind(1, N, query[i]) << " ";
    }
    return 0;
}
