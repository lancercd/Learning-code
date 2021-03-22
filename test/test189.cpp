#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
const int MAXN = 1e3 + 2;
int N, M;
int arr[MAXN][MAXN] = {0};

int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N >> M;
    int x1, x2, y1, y2;
    for(int i=0; i<M; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j=x1; j<=x2; ++j)
        {
            arr[j][y1] += 1;
            arr[j][y2 + 1] -= 1;
        }
    }

    int sum = 0;
    for(int i=1; i<=N; ++i)
    {
        sum = 0;
        for(int j=1; j<=N; ++j)
        {
            sum += arr[i][j];
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
