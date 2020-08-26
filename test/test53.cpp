#include "iostream"
#include "algorithm"

using namespace std;

int A, B, C, is_has = 0;
int result[9] = {0};
bool used[9] = {0};

inline void dfs(int count){
    if(count == 6){
        int a,b;
        a = result[0] * 100 + result[1] * 10 + result[2];
        b = result[3] * 100 + result[4] * 10 + result[5];
        if(b * A != B * a) return;
    }
    if(count == 9){

        int a,b,c;
        a = result[0] * 100 + result[1] * 10 + result[2];
        b = result[3] * 100 + result[4] * 10 + result[5];
        c = result[6] * 100 + result[7] * 10 + result[8];
        if(c * A == C * a)
        {
            cout << a << " " << b << " " << c << endl;
            is_has = 1;
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
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> A >> B >> C;

    dfs(0);
    if(!is_has){
        cout << "No!!!" << endl;
    }
    // next_permutation()
    return 0;
}
