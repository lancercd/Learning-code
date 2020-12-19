#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

const int MAXN = 1e8 + 10;
int arr[MAXN] = {0};
int l[MAXN] = {0};
int r[MAXN] = {0};

int N;

int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    cin >> N;
    for(int i=0; i<N; ++i)
    {
        cin >> arr[i];
    }

    l[0] = arr[0];
    for(int i=1; i<N; ++i)
    {
        l[i] = max(l[i-1], arr[i]);
    }
    r[N-1] = arr[N-1];
    for(int i=N-2; i>-1; --i)
    {
        r[i] = max(r[i+1], arr[i+1]);
    }

    cout << "----" << endl;
    for(int i = 0;  i < N; ++i){
        cout << l[i] << " ";
    }
    cout << endl;
    for(int i = 0;  i < N; ++i){
        cout << r[i] << " ";

    }
    cout << endl;

    --N;
    int ans=0;
    for(int i=0; i<N; ++i)
    {
        // if(l[i] == 0 || r[i] == 0) continue;
        ans += min(l[i], r[i]);
    }
    cout << ans;


    return 0;
}
