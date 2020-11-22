#include "iostream"
#include "algorithm"
#include "cmath"

using namespace std;

int N;
int main() {
    cin >> N;
    int c = N * N;
    int a = 0,b = 0;
    for(int i=1; i<N; ++i){
        a =  i * i;
        b = sqrt(c - a);
        if(a + b*b != c) continue;
        cout << sqrt(a) << " " << b << endl;
        return 0;
    }
    return 0;
}
