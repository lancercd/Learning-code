#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

const int MAXN = 5e4 + 3;
int L, N, M;
int arr[MAXN] = {0};


bool check(int target){
    int move_count = 0;
    int current_index = 0;
    int pre_index = 0;
    while(current_index < N)
    {
        ++current_index;
        if((arr[current_index] - arr[pre_index]) < target){
            ++move_count;
        }else{
            pre_index = current_index;
        }
        if(move_count > M) return false;
    }

    return true;
}

int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> L >> N >> M;
    ++N; arr[N] = L;
    for(int i=1; i<N; ++i) cin >> arr[i];


    int left = 0, right = L, mid = 0, ans = 0;
    while(left <= right){
        mid = left + ((right - left) >> 1);
        if(check(mid)){
            ans = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    cout << ans;


    return 0;
}
