#include "iostream"
#include "algorithm"

using namespace std;
const int MAXN = 2e5 + 5;
int arr[MAXN], dp[MAXN] = {0};


int main(int argc, char const *argv[]) {
    int N; cin >> N;
    for(int i=0; i<N; ++i) cin >> arr[i];
    dp[0] = arr[0];
    for(int i=1; i<N; ++i)
    {
        if(dp[i-1] <= 0) dp[i] = arr[i];
        else dp[i] = dp[i - 1] + arr[i];
    }
    int Max = -9999;
    for(int i=0; i<N; ++i) if(Max < dp[i]) Max = dp[i];

    cout << Max << endl;
    return 0;
}
