#include "iostream"
#include "algorithm"
#include "cmath"

using namespace std;

typedef long long ll;
ll N, LEN, K;
const int MAXN = 1e6 + 10;
int arr[MAXN];

inline ll read()
{
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-')f = -1;ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}
    return x * f;
}
int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    N = read();

    while(N--)
    {
        ll tmp, step = 0;
        tmp = read(), LEN = read(), K = read();
        for(int i = 0;  i < LEN; ++i){
            arr[i] = read();
        }
        if(LEN > 1)
        {
            sort(arr, arr + LEN);

            int i = LEN-1;
            //对第一个进行处理
            if(arr[i] > K)
            {
                step += arr[i] - 1;
                step += arr[i] - K;
            }else if(arr[i] < K)
            {
                step += K - 1;
                step += (K - arr[i]) * 2;
            }
            --i;
            //对中间的进行处理
            for(;  i > 0; --i){
                step += abs(arr[i] - K) *2;
            }

            //对最后一个进行处理
            step += abs(arr[i] - K);
            step += arr[i];


            cout << step - 1 << endl;
        }else{
            if(LEN == 0)
            {
                cout << step<< endl;
            }else{
                int i = LEN-1;
                if(arr[i] > K)
                {
                    step += (arr[i] - 1) * 2;
                }else if(arr[i] < K)
                {
                    step += (K - 1) * 2;
                }
                cout << step<< endl;
            }
        }


    }
    return 0;
}
/*
2
10 2 5
6 7
10 2 5
3 4

1
10 1 5
6
*/
