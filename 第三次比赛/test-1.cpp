#include "iostream"
#include "algorithm"

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    int x,a,y,b;
    double m,n;
    while(cin >> x >> a >> y >> b){
        m = x/a; n = y/b;
        if(m > n){
            cout << '>' << endl;
        }else if((m == n)){
            cout << '=' << endl;
        }else{
            cout << '<' << endl;
        }

    }
    return 0;
}
