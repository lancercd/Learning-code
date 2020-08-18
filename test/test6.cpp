#include "iostream"
#include "vector"
using namespace std;

int result[9] = {0};
int used[9] = {0};
vector<vector<int> > R;
int a,b,c;
void dfs(int count)
{
    if(count == 9)
    {
        a = result[0]*100 + result[1]*10 + result[2];
        b = result[3]*100 + result[4]*10 + result[5];
        c = result[6]*100 + result[7]*10 + result[8];
        if(a*2 == b && a*3 == c)
        {
            // cout << a << " " << b << " " << c << endl;
            vector<int> arr(result, result+9);
            R.push_back(arr);
        }
        return ;
    }
    for(int i=0; i<9; ++i)
    {
        if(used[i] == 0)
        {
            used[i] = 1;
            result[count] = i+1;
            dfs(count + 1);
            used[i] = 0;
        }
    }
}

int main(){

    dfs(0);
    // cout << R.size() << endl;
    for(int i=0; i<R.size(); ++i)
    {
        for(int j=0; j<R[i].size(); ++j)
        {
            cout << R[i][j];
        }

        cout << "  " << endl;
    }


    return 0;
}
