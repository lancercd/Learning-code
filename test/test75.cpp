#include "iostream"
#include "algorithm"
/*
    失败的高精度  重新写  见test76.cpp
 */
using namespace std;
typedef unsigned long long ull;
const ull DIV = 1e10;
int N;
ull arr[3][2];
int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N;
    arr[0][0] = 1;arr[0][1] = 0;
    arr[1][0] = 2;arr[0][1] = 0;
    arr[2][0] = 3;arr[0][1] = 0;
    if(N < 4){
        cout << arr[N-1][0] + arr[N-1][1] * DIV;return 0;
    }
    int count = N - 3;
    while(count--){
        arr[0][0] = arr[1][0];
        arr[0][1] = arr[1][1];
        arr[1][0] = arr[2][0];
        arr[1][1] = arr[2][1];
        arr[2][0] = (arr[0][0] + arr[0][1]*DIV + arr[1][0] + arr[1][1]*DIV)%DIV;
        arr[2][1] = (arr[0][0] + arr[0][1]*DIV + arr[1][0] + arr[1][1]*DIV)/DIV;
    }
    if(arr[2][1] != 0){
        cout << arr[2][1];
    }

    cout << arr[2][0] << endl;
    return 0;
}
