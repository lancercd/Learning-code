#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;


int main() {
  freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    int n;

    cin >> n;
    vector<vector<int>> input(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      input[i][0] = x;
      input[i][1] = y;
    }
    sort(input.begin(), input.end());

    int left = 0, right = n - 1;

    while (input[left][1] != 1 && left < right) {
      left++;
    }
    while (input[right][1] != 1 && left < right) {
      right--;
    }
    int count = 0;
    for (int i = left + 1; i <= right && input[i][0] == input[left][0]; i++) {
      if (input[i][1] == 0) {
        count++;
      }
    }

    for (int i = right - 1; i > left && input[i][0] == input[right][0]; i--) {
      if (input[i][1] == 0) {
          count++;
      }
    }

    int ans = right - left + 1 - count;


    cout << ans << endl;
    if (ans <= 0) return 1;
    return ans;

}
