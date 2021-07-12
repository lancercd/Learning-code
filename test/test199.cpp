#include "iostream"
#include "algorithm"
#include "map"
#include "vector"

using namespace std;

map<int, vector<int>> table;
char chars[101] = {0};
int i = 0;

int main(){
  freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> chars;

    while(chars[i] != '\0'){
        table[chars[i]].push_back(i);
        ++i;
    }

    i = 0;
    while(chars[i] != '\0'){
        vector<int> arr = table[chars[i]];
        int len = arr.size();
        if(len == 0){
          ++i;
          continue;
        }
        for(int j=0; j<len; ++j){
            cout << (char)chars[i] << ":" << arr[j];
            if(j != (len - 1)) cout << ",";

        }
        cout << endl;
        table[chars[i]].clear();

        ++i;
    }

    return 0;
}
