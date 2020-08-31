#include "iostream"
#include "algorithm"
#include "map"

typedef unsigned long long ull;
const int MAXN = 1e5;
std::map<ull, int> map;

int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    int N, Q, op, x, y, w;
    std::cin >> N >> Q;
    for(int i=0; i<Q; ++i){
        std::cin >> op >> x >> y;
        if(op == 1){
            std::cin >> w;
            map[MAXN * x + y] = w;
        }else{
            std::cout << map[MAXN * x + y] << std::endl;
        }
    }

    return 0;
}
