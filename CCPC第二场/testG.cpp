#include "iostream"
#include "algorithm"
#include "map"
#include "string"


const int MAXN = 1e5 + 10;
std::string str;

int N;
std::map<std::string, bool> map;

void front(int index, std::string& rev){
    for(int i=index; i>-1; --i) rev += str[i];
}
void end(int index, std::string& rev){
    for(int i=str.size() - 1; i>index; --i) rev += str[i];
}


int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    while(std::cin >> N){
        map.clear(); str.clear();
        char tmp;
        for(int i=0; i<N; ++i){
            std::cin >> tmp;
            str+=tmp;
        }
        std::string rev;
        for(int i=0; i<N; ++i)
        {
            front(i, rev); end(i, rev);
            map[rev] = true;
            rev.clear();
        }
        int ans = 0;

        std::map<std::string, bool>::iterator iter = map.begin();
        while(iter != map.end()) {
            std::cout << iter->first << " ";
            ++ans;
            ++iter;
        }
        std::cout << std::endl;
        std::cout << ans << std::endl;

    }
    return 0;
}
