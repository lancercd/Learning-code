#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    bool* used;
    int* arr;
    int len;
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int time){
        if(time == len){
            vector<int> tmp(len);
            for(int i=0; i<len; ++i) tmp[i] = arr[i];
            res.push_back(tmp);
            return;
        }
        for(int i=0; i<len; ++i)
        {
            if(used[i]) continue;
            used[i] = 1;
            arr[time] = nums[i];
            dfs(nums, time + 1);
            used[i] = 0;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        used = new bool[len];
        arr = new int[len];
        for(int i=0; i<len; ++i)
        {
            used[i] = 0;
            arr[i] = 0;
        }
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
