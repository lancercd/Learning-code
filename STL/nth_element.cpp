#include "iostream"
#include "algorithm"


using namespace std;
const int MAXN = 5e6 + 2;
int arr[MAXN];
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T, n, k, i; T = read();
    while(T--){
        n = read(); k = read(); for(i=0; i<n; ++i) arr[i] = read();

        nth_element(arr, arr + k -1, arr + n);

        cout << arr[k-1] << endl;
    }

    return 0;
}
