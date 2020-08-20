#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

class Solution {
public:
    // [
    //     [2],
    //     [3,4],
    //     [6,5,7],
    //     [4,1,8,3]
    // ]
    int minimumTotal(vector<vector<int>>& triangle) {
        for(unsigned int i=1; i<triangle.size(); ++i){
            for(unsigned int j=0; j<triangle[i].size(); ++j){
                if(j == triangle[i].size() - 1){
                    triangle[i][j] = triangle[i-1][j-1] + triangle[i][j];
                }else{
                    triangle[i][j] = min(triangle[i-1][j], triangle[i-1][j-1]) + triangle[i][j];
                }
            }
        }
        int max = 0, index = triangle.size() - 1;
        for(unsigned int i=0; i<triangle[index].size(); ++i){
            if(max < triangle[index][i]) max = triangle[index][i];
        }

        return max;
    }
};

int main(int argc, char const *argv[]) {

    Solution * a = new Solution;
    return 0;
}
