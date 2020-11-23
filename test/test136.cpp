#include "iostream"
#include "algorithm"

using namespace std;

bool used[9] = {0};
int result[9] = {0};


void dfs(int timer)
{
    if(timer == 9){
        //check
        int num1 = result[0] * 100 + result[1] * 10 + result[2];
        int num2 = result[3] * 100 + result[4] * 10 + result[5];
        int num3 = result[6] * 100 + result[7] * 10 + result[8];
        if(num1 * 3 == num3){
            cout << num1 << " " << num2 << " " << num3 << endl;
        }
    }

    if(timer == 6){
        int num1 = result[0] * 100 + result[1] * 10 + result[2];
        int num2 = result[3] * 100 + result[4] * 10 + result[5];
        if(num1 * 2 != num2){
            return;
        }
    }

    for(int i=0; i<9; ++i)
    {
        if(used[i]) continue;
        used[i] = 1;
        result[timer] = i + 1;
        dfs(timer + 1);
        used[i] = 0;

    }
}

int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    dfs(0);
    return 0;
}
