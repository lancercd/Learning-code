#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
int n, a, b, c;
int arr[4010] = {0};

void dea(int target) {
  for(int i=target; i<=n; ++i){
    int index = i - target;
    arr[i] = max(arr[i], arr[index] + 1);
  }
}

int main() {
    freopen("../../data/in.txt", "r", stdin); freopen("../../data/out.txt", "w", stdout);
    cin >> n >> a >> b >> c;

    // sort(ele, ele + 3);

    dea(a);
    dea(b);
    dea(c);

    // for(int i=1; i<=n; ++i){
    //   cout << arr[i] << " ";
    // }
    // cout << endl;

    cout << arr[n];


    return 0;
}
