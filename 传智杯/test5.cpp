#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
int n, m;
const int MAXN = 1e5 + 5;
int googs[MAXN] = {0};
int w[MAXN] = {0};
int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> w[i];
    for(int i=0; i<m; ++i) cin >> googs[i];
    sort(w, w + n);
    sort(googs, googs + m);

    int ans = 0;
    int i=0, j=0;
    while(i<n && j < m){
        if(w[i] < googs[j]){
            ++i;
            continue;
        }
        ++j;
        ++i;
        ++ans;
    }


    cout << ans;

    return 0;
}
