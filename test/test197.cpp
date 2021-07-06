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
    if(move_count > M) return false;
    ++cur;
  }
  return true;
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
      ans = mid;
      l = mid + 1;
    }else{
      r = mid - 1;
    }
  }
  cout << ans << endl;

  return 0;
}
