#include "iostream"
#include "algorithm"
#include "climits"
using namespace std;
const int MAXN = 3e5 + 10;
int arr[MAXN] = {0};
int main(int argc, char const *argv[]) {
    int N,M,num;
    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        cin >> num; arr[i] = arr[i-1] + num;
    }

    int Max = INT_MIN;
    for(int i=M; i<=N; ++i){
        int inner_max = INT_MIN, inner_min = INT_MAX;
        for(int j=i-M; j<=i; ++j){
            if(arr[j] > inner_max) inner_max = arr[j];
            if(arr[j] < inner_min) inner_min = arr[j];

        }
        // cout << "in [" << i-M << "," << i << "]" << " inner_max:" << inner_max << " inner_min:" << inner_min << endl;
        Max = max(inner_max - inner_min, Max);
    }
    cout << Max;
    return 0;
}
