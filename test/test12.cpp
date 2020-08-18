#include "iostream"
#include "algorithm"
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int L,M, a, b;
    cin >> L >> M;
    int* arr = new int[L+1];
    fill(arr, arr+L+1, 0);
    while(M--){
        cin >> a >> b;
        for(; a <= b; ++a) arr[a] = 1;
    }
    L+=1;b=0;
    for(a=0; a<L; ++a){
        if(arr[a] == 0) ++b;
    }
    cout << b;

    return 0;
}
