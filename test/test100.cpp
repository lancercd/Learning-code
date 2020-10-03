#include "iostream"
#include "algorithm"

using namespace std;
const int MAXN = 1e5 + 10;
int arr[MAXN] = {0};

int N, M;
void init(){
    int pre = arr[1];
    for(int i = 2; i <= N; ++i)
    {
        int num = arr[i];
        arr[i] -= pre;
        pre = num;

    }
}

void plus_arr(int x, int y, int k)
{
    arr[x] += k;
    arr[y + 1] -= k;
}

void sum_arr(int x, int y){
    int cnt = 0;
    int i;
    for(i=0; i<=x; ++i)
    {
        cnt += arr[i];
    }

    int current = cnt;
    for(; i <= y; ++i)
    {
        current += arr[i];
        cnt += current;
    }
    cout << cnt << endl;
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
