#include "iostream"
#include "algorithm"

using namespace std;

bool used[9] = {0};
int res[9] = {0};

int flag = 0;


void dfs(int cnt)
{
    if(cnt == 9){
        //judge & out
        int num1 = res[0] * 100 +res[1] * 10 + res[2];
        int num2 = res[3] * 100 +res[4] * 10 + res[5];
        int num3 = res[6] * 100 +res[7] * 10 + res[8];
        if(num1 * 3 == num3)
        {
            cout << num1 << " " << num2 << " " << num3 << endl;
        }
        return;
    }

    if(cnt == 6){
        int num1 = res[0] * 100 +res[1] * 10 + res[2];
        int num2 = res[3] * 100 +res[4] * 10 + res[5];
        if(num1 * 2 != num2) return;
    }

    for(int i=0; i<9; ++i)
    {
        if(used[i]) continue;
        used[i] = 1;
        res[cnt] = i + 1;
        dfs(cnt + 1);
        used[i] = 0;
    }


}


int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    dfs(0);

    return 0;
}
