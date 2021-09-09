#include "iostream"
#include "algorithm"
#include "vector"
#include "cstdio"

// https://www.luogu.com.cn/record/57745833
// 二分答案
// 洛谷

using namespace std;
const int MAXN = 5e4 + 5;
int L, N, M, arr[MAXN] = {0};
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-')f = -1;ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}
    return x * f;
}
bool check(int target) {
    int cnt = 0, l = 0, r = 1;
    while (r < N) {
        if (arr[r] - arr[l] < target) ++cnt;
        else l = r;
        if (cnt > M) return false;
        ++r;
    }
    return true;
}

int binary() {
    int l = -1, r = L + 1, m = 0;
    while ((l + 1) != r) {
        m = ((r - l) >> 1) + l;
        if (check(m)) l = m;
        else r = m;
    }
    return l;
}

int main() {
    freopen("../data/in.txt", "r", stdin);
    freopen("../data/out.txt", "w", stdout);
    L = read();
    N = read();
    M = read();
    int i = 1;
    for (; i <= N; ++i) arr[i] = read();
    arr[i] = L;
    ++N;

    cout << binary() << endl;
    return 0;
}


/**
#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

const int MAXN = 5e4 + 10;
int L, N, M;
int arr[MAXN] = {0};

bool check(int target){
  int move_count = 0;
  int cur = 1;
  int pre = 0;
  while(cur < N){
    if((arr[cur] - arr[pre]) < target) ++move_count;
    else pre = cur;
    if(move_count > M) return true;
    ++cur;
  }
  return false;
}

int main(){
  // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
  cin >> L >> N >> M;
  ++N;
  for(int i=1; i<N; ++i) cin >> arr[i];
  arr[N] = L;
  ++N;

  int l = 0, r = L, mid = 0, ans = 0;
  while(l <= r){
    mid = l + ((r - l) >> 1);
    if(check(mid)){
      r = mid - 1;
    }else{
      ans = mid;
      l = mid + 1;
    }
  }
  cout << ans << endl;

  return 0;
}

*/
