#include "iostream"
#include "algorithm"
#include "set"

using namespace std;
const int MAXN = 1e3 + 2;
int arr[MAXN] = {0};
int N;
int M;

int main() {
  freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
  cin >> N ;

  while(N--){
    cin >> M;
    for(int i=0; i<M; ++i) cin >> arr[i];
    set<int> table(arr, arr + M);
    if(table.size() != M || *(table.begin()) != 1) {
      cout << "No" << endl;
    }else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
