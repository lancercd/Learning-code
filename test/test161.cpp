#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (0 == matrix.size() || 0 == matrix[0].size()) return false;
        int m = matrix[0].size(), n = matrix.size();

        int x = m - 1, y = 0;
        while (x > -1 && y < n) {
            if (matrix[y][x] == target) return true;
            if (matrix[y][x] < target) ++y;
            else --x;
        }
        return false;

    }
};
int main() {
    Solution* solu = new Solution();
    vector<vector<int>> matrix = {
      {1,   4,  7, 11, 15},
      {2,   5,  8, 12, 19},
      {3,   6,  9, 16, 22},
      {10, 13, 14, 17, 24},
      {18, 21, 23, 26, 30}
    };

    cout << solu->findNumberIn2DArray(matrix, 27) << endl;
    return 0;
}
