#include "iostream"
#include "algorithm"

using namespace std;
const int MAXN = 1e5 + 10;
int arr[MAXN] = {0};

int N, M;
void init(){
    for(int i=2; i<=N; ++i)
    {
        arr[i] += arr[i-1];
    }
}

void plus_arr(int x, int y, int k)
{
    int time = 0, i=x;
    for(; i<=y; ++i)
    {
        ++time;
        arr[i] += time * k;
    }

    for(; i <= N; ++i)
    {
        arr[i] += time * k;
    }
}

void sum_arr(int x, int y){
    cout << arr[y] - arr[x - 1] << endl;
}


int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    int op, x, y, k;
    cin >> N >> M;
    for(int i=1; i<=N; ++i)
    {
        cin >> arr[i];
    }
    init();
    while(M--)
    {
        cin >> op >> x >> y;
        if(op == 1){
            cin >> k;
            plus_arr(x, y, k);
        }else{
            sum_arr(x, y);
        }
    }

    return 0;
}
