#include "iostream"
#include "algorithm"

using namespace std;
const int MAXN = 1e7 + 5;
int arr[MAXN] = {0};
int L, N, K;


//这段距离  需要填充多少次  才行
int myDiv(int num1, int num2){
    int ans = num1 / num2;
    if(num1 % num2 != 0) ++ans;

    return ans - 1;
}


bool check(int target){
    if(target == 0) return false;
    int pre = 0, current = 0;
    int put_count = 0;
    int div = 0;
    while(current < N){
        ++current;
        div = arr[current] - arr[pre];
        if(div > target){
            put_count += myDiv(div, target);
        }
        ++pre;

        if(put_count > K) return false;
    }

    return true;
}

int main(){
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> L >> N >> K;
    for(int i=0; i<N; ++i) cin >> arr[i];
    --N;
    int left = 0, right = arr[N], mid = 0;
    int ans = 0;
    while(left <= right)
    {
        mid = left + ((right - left) >> 1);
        if(check(mid)){
            right = mid - 1;
            ans = mid;
        }else{
            left = mid + 1;
        }
    }
    cout << ans;

    return 0;
}
