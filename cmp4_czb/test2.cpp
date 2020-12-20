#include "iostream"
#include "algorithm"
#include "vector"
#include "cmath"
#include "cstdio"

using namespace std;
int X;
int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> X;
    if(X >= 90){
        printf("4.0");
        return 0;
    }else if(X >= 60){
        printf("%.1f", 4.0 - ((90 - X) * 0.1));
        return 0;
    }else{
        int x = sqrt(X) * 10;
        if(x < 60){
            printf("0.0");
            return 0;
        }
        printf("%.1f", 4.0 - ((90 - x) * 0.1));
        return 0;
    }
    return 0;
}
