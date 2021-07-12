#include "iostream"
#include "algorithm"
#include "vector"
#include "string"

using namespace std;

class Solution {
    char *str;
    vector<string> arr;
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return arr;
        this->str = new char[2 * n + 1];
        this->str[2 * n] = '\0';
        dfs(0, n, n);


        return this->arr;
    }

    void dfs(int index, int left, int right){

      if(left == 0 && right == 0) arr.push_back(str);

      if(left != 0){
        str[index] = '(';
        dfs(index + 1, left - 1, right);
      }

      if(right > left){
        str[index] = ')';
        dfs(index + 1, left, right - 1);
      }
    }

};

int main(){

  Solution *sulo = new Solution();
  vector<string> arr = sulo->generateParenthesis(0);

  for(unsigned int i=0 ;i<arr.size(); ++i){
    cout << arr[i] << endl;
  }

  return 0;
}
