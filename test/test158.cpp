#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;


// 全排列  使用swap  而非用used标记  代码更简洁   但是最后结果会有差异
/*
    使用swap
    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 2 1     <-------
    3 1 2   <---

    使用used标记
    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 1 2     <-------
    3 2 1   <---

    可以看大有不一样的地方
 */
class Solution {
public:
    int len;
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int time){
        if(time == this->len){
            res.emplace_back(nums);
            return;
        }
        for(int i=time; i<this->len; ++i)
        {
            swap(nums[i], nums[time]);
            dfs(nums, time + 1);
            swap(nums[i], nums[time]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        this->len = nums.size();
        dfs(nums, 0);
        return res;
    }
};


int main() {
    Solution* solu = new Solution();
    vector<int> arr = {1,2,3};
    vector<vector<int>> res = solu->permute(arr);

    for(int i = 0;  i < res.size(); ++i){
        for(int j = 0;  j < res[i].size(); ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
