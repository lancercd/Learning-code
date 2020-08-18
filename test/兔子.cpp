#include "iostream"
using namespace std;

long S(int m, int n){
    if(m < 2 || n < 2)
        return 1;
    if(n > m)
        return S(m, m);
    else{
        return S(m, n-1) + S(m - n, n);
    }
}


int main(){
    int m, n;
    while(cin >> m >> n)
        cout << S(m, n) << endl;
    return 0;
}
