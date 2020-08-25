#include "iostream"
#include "algorithm"

using namespace std;
typedef unsigned long long ull;


ull mypower(ull a, ull n, ull mod) {
    ull ret = 1;
    while (n) {
        if (n & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}
int main() {
    int T;scanf("%d", &T);
    while(T--){
        ull a,b,c; scanf("%llu%llu%llu", &a, &b, &c);
        printf("%llu\n", mypower(a,b,c));
    }
    return 0;
}
