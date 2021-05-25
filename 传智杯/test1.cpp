#include "iostream"
#include "algorithm"
#include "vector"
#include "map"


using namespace std;
int n, m;
int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    int tmp = 0;
    map<int, int> table;
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        table[tmp] = 1;
    }
    int ans = 0;
    for(int i=0; i<m; ++i){
        cin >> tmp;
        if(table.find(tmp)!=table.end()) ++ans;
    }
    cout << ans;
    return 0;
}
