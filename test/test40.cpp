#include "iostream"
#include "algorithm"
#include "climits"
using namespace std;
const int MAXN = 1e3 + 10;
int arr[MAXN][MAXN] = {0};
int main(int argc, char const *argv[]) {
    int N; cin >> N;
    for(int i=1; i<=N; ++i)
    {
        for(int j=1; j<=i; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=2; i<=N; ++i)
    {
        for(int j=1; j<=i; ++j)
        {
            arr[i][j] += max(arr[i-1][j], arr[i-1][j-1]);
        }
    }
    int Max = INT_MIN;
    for(int i=1; i<=N; ++i)
    {
        if(Max < arr[N][i]) Max = arr[N][i];
    }
    cout << Max << endl;
    return 0;
}
