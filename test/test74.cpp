#include "iostream"
#include "algorithm"
using namespace std;
int N, M;
int ans[11] = {0};
int main() {
    cin >> N >> M;
    for(int i=N; i<=M; ++i){
        int tmp = i, pos = 0;
        while(tmp){
            pos = tmp - tmp / 10 * 10;
            ++ans[pos];
            tmp/=10;
        }
    }

    for(int i=0; i<10; ++i)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
