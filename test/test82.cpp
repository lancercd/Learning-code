#include "iostream"
#include "algorithm"
#include "climits"
using namespace std;
const int MAXN = 5000;  //数组中最多元素个数
int arr[MAXN] = { 0 },dp[MAXN] = { 0 };
int main() {
    int N; cin >> N;   //含有  N个元素
    for (int i = 0; i < N; ++i) cin >> arr[i];  //输入数组中的元素
    for (int i = 0; i <= N; ++i) dp[i] = INT_MAX;  //讲  dp  中每个元素  复制位int的最大值
    // ----------- 输入完成 -------------
    dp[0] = 0;   //到dp[0]  只需要0步
    for (int i = 0; i < N; ++i)
    {
        int time = arr[i];  //当前可以跳多少次
        int j = i + 1;
        while (time && j < N) {  //在不超出数组的情况下  跳
            dp[j] = min(dp[j], dp[i] + 1);
            ++j;
            --time;
        }
    }
    cout << dp[N - 1] << endl;
    return 0;
}
