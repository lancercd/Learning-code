#include "iostream"
#include "algorithm"
#include "cmath"
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

const ull MOD = 998244353;
const ull MAXN = 1e5 + 10;
int b[MAXN] = { 0 };
int c[MAXN] = { 0 };

ull f2[MAXN] = { 0 }, arr[MAXN] = { 0 };

int T;
int LEN = 0;

template<class T>inline void read(T& res)
{
    char c; T flag = 1;
    while ((c = getchar()) < '0' || c > '9')if (c == '-')flag = -1; res = c - '0';
    while ((c = getchar()) >= '0' && c <= '9')res = res * 10 + c - '0'; res *= flag;
}


inline void call(int time) {
    
    for (register int i = 0; i < LEN; ++i) {
        arr[i] *= c[time];
    }
    for (register int i = 0; i < LEN - 1; ++i) {
        f2[i] = (arr[i + 1] * (i + 1)) * b[time];
    }
    f2[LEN - 1] = 0;

    for (register int i = 0; i < LEN; i++) {
        arr[i] += f2[i];
    }
}

int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    read(T);

    while (T--)
    {
        int N;
        read(N);
        LEN = N+1;
        register int tmp = N-1;

        for (register int i = 0; i < LEN; ++i) {
            read(arr[i]);
        }

        for (register int i = 0; i < tmp; ++i) {
            read(b[i]);
        }
        for (register int i = 0; i < tmp; ++i) {
            read(c[i]);
        }


        register int time = 0;

        while (--N)
        {
            call(time++);
        }

        for (register int i = 0; i < LEN; ++i) {
            cout << arr[i] % MOD << " ";
        }
        cout << endl;

    }


    return 0;
}

/*
3
3
0 0 0 1
1 1
1 1
4
1 1 1 1 1
1 2 1
2 3 2
5
3 4 5 6 5 4
4 1 6 0
6 9 2 7

 */
