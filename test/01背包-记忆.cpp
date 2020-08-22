#include "iostream"
#include "algorithm"
#include "utility"
using namespace std;
#define _v second  //价值
#define _w first   //重量   体积
const int MAXN = 1e3 + 5;
pair<int,int> arr[MAXN];
int dp[MAXN];  // dp[i] 在i体积下  的value
int main(int argc, char const *argv[]) {
    int N,V; cin >> N >> V; for(int i=0; i<N; ++i) {cin >> arr[i]._w >> arr[i]._v;}

    //dp 中填充-1 表示在 没有物品能够组成 该体积  则将其value 设为-1
    fill(dp, dp + V + 2, -1); dp[0] = 0;dp[arr[0]._w] = arr[0]._v;

    for(int i=1; i < N; ++i){  //从第一个物品开始
        for(int j = V - arr[i]._w; j > -1; --j){
            if(dp[j] != -1){   //  j  体积下有value
                int total_w = j + arr[i]._w;   //在原有的体积j上  加上 i 物品的体积
                if(total_w > V) continue;       //超出了最大体积   不考虑
                dp[total_w] = max(dp[total_w], dp[j] + arr[i]._v);
                 // 在total_w的体积下 可能已经有value了   则选出最大值
            }
        }
    }

    int Max = -999;
    // 在所有的体积中  选出价值最大的（value 最大的）
    for(int i = V; i > -1; --i) if(dp[i] != -1 && dp[i] > Max) Max = dp[i];
    cout << Max << endl;
    return 0;
}
