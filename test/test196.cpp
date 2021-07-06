#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

const int MAXN = 1e6 + 10;
int n, m;
int arr[MAXN] = {0};

int binary(int target){
  //开始二分
  int l = 0, r = n, mid = 0, ans = -1;
  while(l <= r){
    mid = l + ((r - l) >> 1);
    if(arr[mid] == target) ans = mid;
    if(arr[mid] >= target){
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  return ans == -1? -1 : ans + 1;
}

int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> n >> m ;
    for(int i=0; i<n; ++i){
      cin >> arr[i];
    }
    int target = 0;

    for(int i=0; i<m; ++i){
      cin >> target;
      cout << binary(target) << " ";

    }
    return 0;
}
