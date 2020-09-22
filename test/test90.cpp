#include "iostream"
#include "algorithm"
#include "map"
#include "vector"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e3 + 10;
const int MAXQ = 2e3 + 10;
const ll MOD = 4294967296;
int a[MAXN] = { 0 }, v[MAXN] = { 0 };
int l[MAXQ] = { 0 }, r[MAXQ] = { 0 }, x[MAXQ] = { 0 };
int N, M, Q;
vector<ll> save;



void getF(int left, int right, int sum, int cnt, map<int, int>& arr) {
    if (left > right) return;
    if (cnt > M - 1) return;
    //不加当前的数
    getF(left + 1, right, sum, cnt, arr);

    //加当前的数
    int _sum = sum + v[left];
    int _cnt = cnt + a[left];
    if (_cnt > M - 1) return;
    arr[_cnt] = _sum + 1;
    getF(left + 1, right, _sum, _cnt, arr);

}

void game(int left, int right, int x) {
    map<int, int> arr;
    getF(left, right, 0, 0, arr);
    ll sum = 0;
    // for (int i = 0; i < M; ++i)
    // {
    //     if (x == i) continue;
    //     sum += arr[i] - 1;
    // }
    // sum %= MOD;
    // save.push_back(sum);
    // cout << "ans:" << sum << " | ";
    sum = 0;
    for (int i = 0; i < M; ++i)
    {
        if (x == i) continue;
        cout << arr[i] - 1 << " ";
    }
    cout << endl;


}


int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N >> M >> Q;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i] >> v[i];
    }
    for (int i = 0; i < Q; ++i)
    {
        cin >> l[i] >> r[i] >> x[i];
    }

    for (int i = 0; i < Q; ++i)
    {
        game(l[i], r[i], x[i]);
    }
    // game(l[0], r[0], x[0]);
    ll sum = 0;
    for (int i = 1; i <= Q; ++i)
    {
        if (i == save[i - 1]) continue;
        sum += save[i - 1];
    }
    cout << sum << endl;


    return 0;
}
