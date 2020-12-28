#include "iostream"
#include "algorithm"

using namespace std;
typedef unsigned long long ull;
const ull mod = 1e9 + 7;
int N, K;
ull ans = 0;
ull num = 0;
void dfs(int cnt){
    if(cnt == N){
        if(num % K == 0){
            ++ans;
            ans %= mod;
        }
        return;
    }
    for(int i=0; i<6; ++i){
        num = num * 10 + i + 1;
        dfs(cnt + 1);
        num /= 10;
    }

}

int main() {
    cin >> N >> K;
    dfs(0);

    cout << ans << endl;
    return 0;
}
