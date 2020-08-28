#include "iostream"
#include "algorithm"
#include "cmath"
#include "cstdio"

using namespace std;
typedef long long ll;
const int MAXN = 25;
int arr[MAXN] = {0}, used[MAXN] = {0}, result[MAXN] = {0}, N, K, ans = 0;

bool isPrime(int n){
    if(n < 2) return 0;
    if(n == 2 || n == 3) return 1;
    if(n % 6 != 1 && n % 6 != 5) return 0;
    int sq = sqrt(n);
    for(int i = 5; i <= sq; i+=6){
        if(n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

void dfs(int count,int index)
{
    if(count == K){
        int sum = 0;
        for(int i = 0;  i < K; ++i) sum += result[i];
        if(isPrime(sum)) ++ans;
    }else{
        for(int i = index;  i < N; ++i){
            if(used[i]) continue;
            used[i] = 1;
            result[count] = arr[i];
            dfs(count + 1, i);
            used[i] = 0;
        }
    }
}
int main() {
    cin >> N >> K;
    for(int i = 0;  i < N; ++i) cin >> arr[i];

    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
