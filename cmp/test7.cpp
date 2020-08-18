#include "iostream"
#include "algorithm"

using namespace std;
const int MAXN = 1e5 + 3;
int arr[MAXN];
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N, i, total=0; cin >> N;
    for(i=0; i<N; ++i) {cin >> arr[i]; total += arr[i];}

    int half = total/2, count = 0, index=0, ans=0;
    for(i=0; i<N; ++i){
        while(count < half){
            count += arr[index++];
            if(index == N) index = 0;
        }
        ans = max(ans, min(count, total-count));
        count-=arr[i];
    }

    cout << ans;
    return 0;
}
