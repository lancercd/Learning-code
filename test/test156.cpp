#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "stack"

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        stack<char> sta;
        for(int i=0; i<len; ++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') sta.push(s[i]);
            else{
                char ch = sta.top();
                sta.pop();
                if((s[i] == ')' && ch == '(') ||
                    (s[i] == '}' && ch == '{') ||
                    (s[i] == ']' && ch == '['))
                    return false;
            }
        }
        if(sta.size() != 0) return false;
        return true;
    }
};

int main() {
    Solution* solu = new Solution();
    cout << solu->isValid("()");
    return 0;
}
