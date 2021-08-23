#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "set"

using namespace std;
class Solution {
    void dfs(int level, string str, const int len, set<string> &s) {
        if(level == len){
            s.insert(str);
            return;
        }

        for(int i=0; i<len; ++i){
            swap(str[level], str[i]);
            dfs(level + 1, str, len, s);
            swap(str[level], str[i]);
        }
    }

public:
    vector<string> Permutation(string str) {
        int len = str.size();
        if(len == 0) return {};
        set<string> s;
        this->dfs(0, str, len, s);

        return vector<string>({s.begin(), s.end()});
    }
};
int main() {
    Solution solu;
    vector<string> ans = solu.Permutation("123");
    // vector<string> ans = solu.Permutation("aa");

    for(int i=0; i<ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
