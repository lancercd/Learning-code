#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

int A, B, C;
int result[9] = {0};
bool used[9] = {0};
vector<vector<int> > arr;
inline void dfs(int count){
    if(count == 9){

        int a,b,c;
        a = result[0] * 100 + result[1] * 10 + result[2];
        b = result[3] * 100 + result[4] * 10 + result[5];
        c = result[6] * 100 + result[7] * 10 + result[8];
        if(b == B * a && c == C * a)
        {
            vector<int> tmp;
            tmp.push_back(a);
            tmp.push_back(b);
            tmp.push_back(c);
            arr.push_back(tmp);
        }
    }else{
        for(int i=0; i<9; ++i)
        {
            if(used[i]) continue;
            used[i] = 1;
            result[count] = i + 1;
            dfs(count + 1);
            used[i] = 0;
        }
    }
}

int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> A >> B >> C;

    dfs(0);
    return 0;
}
