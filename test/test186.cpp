#include "iostream"
#include "algorithm"
#include "cstdio"

using namespace std;

const int MAXN = 1e4;
int arr[MAXN] = {0};
int N, K;

bool check(int target)
{
    if(target < 1) return false;
    int cnt = 0;
    for(int i=0; i<N; ++i)
    {
        cnt += (arr[i] / target);
        if(cnt >= K) return true;
    }

    return false;
}



int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N >> K;
    float tmp = 0;
    for(int i=0; i<N; ++i){
        cin >> tmp;
        arr[i] = tmp * 100;
    }
    int left = 0, right = 10000000, mid = 0, ans = 0;
    //这里不知道为什么   如果right为数组中的最大值  不能过
    //但是 提升了下  right 到 1e7 (边界)  就过了
    while(left <= right)
    {
        mid = left + ((right - left) >> 1);
        if(check(mid)){
            left = mid + 1;
            ans = mid;
        }else{
            right = mid - 1;
        }
    }
    printf("%.2f", ans / 100.0);


    return 0;
}
