#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
typedef long long ll;
const int MAXN = 22;
ll a, b, c;

ll arr[MAXN][MAXN][MAXN] = {0};
ll w(ll a, ll b, ll c) {
  if( a <= 0 || b <= 0 || c <= 0) return 1;
  else if( a > 20 || b > 20 || c > 20){
    if(arr[20][20][20] == 0) arr[20][20][20] = w(20, 20, 20);
    return arr[20][20][20];
  }

  else if( arr[a][b][c] != 0) return arr[a][b][c];

  else if(a < b && b < c){
    if(arr[a][b][c] == 0){
      arr[a][b][c] = w( a, b, c - 1)
                    + w( a, b - 1, c - 1)
                    - w( a, b - 1, c);
    }
    return arr[a][b][c];
  }

  arr[a][b][c] = w(a - 1, b, c)
                + w(a - 1, b - 1, c)
                + w(a - 1, b, c - 1)
                - w(a - 1, b - 1, c - 1);
  return arr[a][b][c];
}



int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    arr[0][0][0] = 1;
    while(cin >> a >> b >> c) {
      if(a == -1 && b == -1 && c == -1) return 0;

      cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
    return 0;
}
