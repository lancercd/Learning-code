#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
class Solution {
private:
    int _x[4] = {0, 0, -1, 1};
    int _y[4] = {-1, 1, 0, 0};
    int ans = 0;

public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>>
     * @return int整型
     */
    int solve(vector<vector<char> >& grid) {
        // write code here
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == '1'){
                    this->dfs(i, j, n, m, grid);
                    ++this->ans;
                }
            }
        }

        return this->ans;
    }
    void dfs(int x, int y, const int n, const int m, vector<vector<char> >& grid) {
        if(grid[x][y] != '1') return;
        grid[x][y] = '0';
        for(int i=0; i<4; ++i){
            int cur_x = x + this->_x[i];
            int cur_y = y + this->_y[i];
            if(cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >= m) continue;
            dfs(cur_x, cur_y, n, m, grid);
        }
    }
};
