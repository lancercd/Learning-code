#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
typedef long long ll;
vector<char> arr;
ll m, n;

inline ll read()
{
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-')f = -1;ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}
    return x * f;
}

int main() {
    // freopen("../../data/in.txt", "r", stdin); freopen("../../data/out.txt", "w", stdout);
    char ch;
    while(cin >> ch){
        if(ch == ',' || ch == ' ') break;
        arr.push_back(ch);
    }
    m = read(); n = read();
    ll len = arr.size();

    ll index = 0;
    while(index < m) cout << arr[index++];
    index = n;
    while(index >= m) cout << arr[index--];
    index = n + 1;
    while(index < len) cout << arr[index++];

    return 0;
}
