#include "iostream"
#include "algorithm"

using namespace std;
int N, M;
const int MAXN = 1e6 + 10, MAXM = 1e5 + 10;
int arr[MAXN], query[MAXM];
int main() {
    cin >> N >> M;
    for(int i=0; i<N; ++i) cin >> arr[i];
    for(int i=0; i<M; ++i) cin >> query[i];
    for(int i=0; i<M; ++i){
        int index = lower_bound(arr, arr + N, query[i]) - arr;
        arr[index] == query[i] ? cout << index + 1: cout << -1;
        cout << " ";
    }
    return 0;
}
