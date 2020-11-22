#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

int check(int num){
    int cnt = 0;
    while(num){
        cnt += num - num / 10 * 10;
        num = num / 10;
    }
    return cnt == 9;
}
int N;
int main() {
    cin >> N;
    if(N < 9){
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for(int i=8; i<=N; ++i)
    {
        if(check(i)){
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
