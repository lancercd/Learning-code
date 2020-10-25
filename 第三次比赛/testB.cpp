#include "iostream"
#include "algorithm"
#include "string"

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int MAXN = 1e5 + 10;
ll N, L;
typedef struct Node { string name; ll v; }Node;
Node arr[MAXN];


bool cmp(Node a, Node b)
{
    return a.v < b.v;
}

int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N >> L;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i].name >> arr[i].v;
    }
    sort(arr, arr + N, cmp);

    for (int i = 1; i < N; ++i) {
        ll dis = arr[i - 1].v * i;
        ll circle = dis / L;
        ll sub = (circle * L == dis)? 0:(L - (dis - L*circle));
        cout << arr[i - 1].name << " " << circle << " " << sub << endl;
    }
    cout << arr[N - 1].name;
    return 0;
}
