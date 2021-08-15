#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
const int MAXN = 1e3 + 2;


typedef struct node {
  int pos;
  int to;
  int isDel;
  int index;
  int ans;
}Node;

Node arr[MAXN];

int N;

int orderOyPos(Node a, Node b) {
  return a.pos < b.pos;
}
int orderOyIndex(Node a, Node b) {
  return a.index < b.index;
}

void showAns() {
  //ans
  sort(arr, arr + N, orderOyIndex);

  for(int i=0; i<N; ++i){
    cout << arr[i].ans << endl;
  }

}

int main() {
  freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N;
    if(N == 0) return 0;
    if(N == 1){cout << -1 << endl; return 0;}

    char to;
    int res = N;

    for(int i=0; i<N; ++i){
      cin >> arr[i].pos;
      cin >> to;
      arr[i].to = (to == 'R')? 1 : 0;
      arr[i].isDel = 0;
      arr[i].index = i;
      arr[i].ans = -1;
    }

    sort(arr, arr + N, orderOyPos);


    while(res > 0){
      int l = 0, r = N - 1;

      //去除首尾
      while(l < N && arr[l].to == 0 && arr[l].isDel == 0) --res, arr[l++].isDel = 1;
      while(r > -1 && arr[r].to == 1 && arr[r].isDel == 0) --res,arr[r--].isDel = 1;

      if(res > 0){
        // r = l + 1;
        // while(r < N && arr[r].isDel == 0) ++r;
        // if(r < N){
        //
        // }
        r = l + 1;
        while(r < N && arr[r].isDel == 0 && arr[r].to == 0) ++r;
        if(r >= N) {
          showAns();
          return 0;
        }

        while(l < N && arr[l].isDel == 0 && arr[l].to == 1) ++l;
        if(l >= N) {
          showAns();
          return 0;
        }




      }

    }

    showAns();

    return 0;
}
