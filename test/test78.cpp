#include "iostream"
#include "algorithm"
#include "cstdbool"
#include "cstdio"
#include "vector"

using namespace std;
const int MAXN = 5e3 + 10, LEN = 10;
int N;

int result[10] = { 0 };
vector< vector<int> > arr;
void dfs(int current, int plus){
    if(current == LEN){
        if(plus == N){
            vector<int> tmp(result, result + LEN);
            arr.push_back(tmp);
        }
        return;
    }
    for(int j=0; j<3; ++j){
        result[current] = j + 1;
        dfs(current + 1, plus + j + 1);
    }
}

int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    cin >> N;
    dfs(0, 0);
    int length = arr.size();
    cout << length << endl;
    for(int i =0; i<length; ++i)
    {
        for(unsigned int j=0; j<arr[i].size(); ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
