#include "iostream"
#include "algorithm"
#include "vector"
#include "queue"

using namespace std;

class Solution {
public:
    int dir[4][2] = {{-1,0}, {0, -1}, {0, 1}, {1, 0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int len = grid.size();
        if(len == 0) return 0;
        int ans = 0;
        for(int i=0; i<len; ++i)
        {
            for(int j=0; j<grid[i].size(); ++j)
            {
                if(grid[i][j] == 1) ans = max(ans, this->dfs(i, j, grid));
            }
        }
        return ans;

    }

    int dfs(int x, int y, vector<vector<int>>& grid){
        int field = 1;
        grid[x][y] = 2;
        queue<pair<int, int> > que;
        que.push({x, y});
        while(!que.empty()){
            auto cur = que.front();
            que.pop();
            for(int i=0; i<4; ++i)
            {
                int dx = cur.first + dir[i][0], dy = cur.second + dir[i][1];
                if(dx < 0 || dy < 0 || dx >= grid.size() || dy >= grid[dx].size()) continue;
                if(grid[dx][dy] == 1){
                    que.push({dx, dy});
                    grid[dx][dy] = 2;
                    ++field;
                }
            }
        }
        return field;
    }


    // void show(vector<vector <int> > &arr){
    //     for(int i=0; i<arr.size(); ++i)
    //     {
    //         for(int j=0; j<arr[i].size(); ++j)
    //         {
    //             cout << arr[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
};


int main() {
    vector<vector<int> > arr = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
     };


    Solution* solu = new Solution();
    cout << solu->maxAreaOfIsland(arr);

    return 0;
}
/*
{
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}
 }
*/
