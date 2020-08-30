#include "iostream"
#include "cstdio"

using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 10;
int N, K;
int arr[MAXN];
bool check(int target){
    if(target < 1) return false;
    ll count = 0;
    for(int i=0; i < N; ++i)
    {
        count += arr[i]/target;
    }
    return count >= K;
}
ll binarySearch(int left, int right){
    int ans = 0;
    while(left <= right){
        int mid = (left + right) >> 1;
        if(check(mid)){ans = mid; left = mid + 1;}
        else right  = mid - 1;
    }
    return ans;
}

int main(){
    scanf("%d%d", &N, &K); int Max = 0;
    for(int i=0; i<N; ++i) {scanf("%d", arr+i); if(arr[i] > Max){Max = arr[i];}};

    cout << binarySearch(0, Max) << endl;
    return 0;
}
