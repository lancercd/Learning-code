#include "iostream"
#include "algorithm"

using namespace std;
const int MAXN = 1e5+5;
int arr[MAXN], cmp[MAXN];
int main(){
    int N, i, flag, count=0; cin >> N;
    for(i=0; i < N; ++i) { cin >> arr[i]; cmp[i] = arr[i];} sort(cmp, cmp + N);
    for(i=0; i<N; ++i) {
        while(cmp[i] != arr[i]) {
            flag = lower_bound(cmp, cmp + N, arr[i]) - cmp;++count;
            swap(arr[i], arr[flag]);
         }
    }
    cout << count;
    return 0;
}
