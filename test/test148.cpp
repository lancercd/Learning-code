#include "iostream"
#include "algorithm"

using namespace std;
const int MAXN = 1e6, MAXM = 1e5;

int arr[MAXN] = {0};
// int query[MAXM] = {0};
int M, N, target;

int find(){
    int left = 0, right = N + 1, mid = 0, ans = -1;

    while(left <= right)
    {
        mid = (left + right) >> 1;
        if(arr[mid] == target) ans = mid;
        if(arr[mid] < target) left = mid + 1;
        else{right = mid - 1;}
    }

    return (-1 == ans)? -1 : ans + 1;
}

int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N >> M;
    for(int i=0; i<N; ++i) cin >> arr[i];
    for(int i=0; i<M; ++i){
        cin >> target;
        cout << find() << " ";
    }

    return 0;
}
