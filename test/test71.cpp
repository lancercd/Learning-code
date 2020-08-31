#include "iostream"
#include "algorithm"
#include "map"

std::map<int, std::map<int, int> > map;

int main() {
    int N, Q, op, x, y, w;
    std::cin >> N >> Q;
    for(int i=0; i<Q; ++i){
        std::cin >> op >> x >> y;
        if(op == 1){
            std::cin >> w;
            map[x][y] = w;
        }else{
            std::cout << map[x][y] << std::endl;
        }
    }

    return 0;
}
