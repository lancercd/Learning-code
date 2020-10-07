#include "iostream"
#include "algorithm"
#include "cstring"
// #include "set"

//字符串哈希
//https://www.luogu.com.cn/problem/solution/P3370

typedef unsigned long long ull;

int N;
char str[1500];
ull hash[10010];

ull base = 131;
ull mod = 212370440130137957LL;
// std::set<ull> arr;

ull hash_code(char str[]){
    int code = 1;
    for(int i=0; str[i]; ++i)
    {
        code = (code * base + (ull)str[i]) % mod + 233317;
    }

    return code;
}

int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    std::cin >> N;
    for(int i=0; i<N; ++i)
    {
        std::cin >> str;
        hash[i] = hash_code(str);
    }

    std::sort(hash, hash + N);
    // for(int i=0; i<N; ++i)
    // {
    //     std::cout << hash[i] << " ";
    // }
    // std::cout << std::endl;
    int ans = 1;

    for(int i=1; i<N; ++i)
    {
        if(hash[i] != hash[i - 1]) ++ans;
    }

    std::cout << ans;

    return 0;
}
