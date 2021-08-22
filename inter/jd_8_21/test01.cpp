#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
const int MAXN = 100000;
typedef struct node { int val, is;}Node;
Node arr[MAXN];
int N;

int cmp(Node a, Node b){
  return a.val < b.val;
}

int dfs(int index){
  int next = index + 1;
  if(next >= N) return 0;
  if(arr[index].val != arr[next].val) return 0;

  if(dfs(index + 1) == 1){
    arr[index].is = 0;
  }
  return 1;
}

void det() {
  for(int i=0; i<N; ++i){
    int next = i + 1;
    if(next >= N || arr[i].val != arr[next].val) continue;
    int flag = (arr[i].is == 1)? 0 : 1;
    while(next < N && arr[i].val == arr[next].val){
      if(arr[next].is == 0) flag = 1;
      ++next;
    }
    if(flag == 1){
      for(int j = i; j< next && j < N; ++j) arr[j].is = 0;
    }

  }
}

int main() {
  freopen("../../data/in.txt", "r", stdin); freopen("../../data/out.txt", "w", stdout);
    cin >> N;
    for(int i=0; i<N; ++i) cin >> arr[i].val >> arr[i].is;
    sort(arr, arr + N, cmp);
    det();
    int left = N + 1, right = -1;


    for(int i=0; i<N; ++i){
      if(arr[i].is == 1){
        left = i;
        break;
      }
    }
    for(int i=N - 1; i>-1; --i){
      if(arr[i].is == 1){
        right = i;
        break;
      }
    }

    for(int i=0; i<N; ++i){
      cout << arr[i].val << "  " << arr[i].is << endl;
    }

    cout << "left:" << left << "  right:" << right << endl;

    cout << ((right >= left)? (right - left  + 1) : 0) << endl;


    return 0;
}
