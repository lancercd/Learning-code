#include "iostream"
#include "algorithm"

using namespace std;
const int MAXN = 1e5 + 10;
int arr[MAXN];
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-')f = -1;ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}
    return x * f;
}
int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);cout.tie(0);
    int n = read(), ans = 0;
    for(int i = 0;  i < n; ++i){
        arr[i] = read();
    }
    for(int i = 0;  i < n; ++i){
        for(int j = i + 1;  j < n; ++j){
            if(arr[i] > arr[j]) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
