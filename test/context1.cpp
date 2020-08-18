#include <iostream>
#include <ctime>

using namespace std;
typedef long long unsigned llu;

llu fib(int n){
    if(n < 1) return 0;
    else if(n==1 || n==2) return 1;
    else return fib(n-1) + fib(n-2);
}
long long unsigned dp(int n){
    llu *a = new llu[n+1];
    int i=0;
    a[0] = 0;a[1] = 1;a[2] = 1;a[3] = 2;
    for(i=4; i<=n; ++i)
    {
        a[i] = a[i-1] + a[i-2];
    }

    return a[n];


}


int main(){
    time_t start = clock(), end;
    int n = 50;
    llu count =0;

    // count = fib(n);
    count = dp(n);

    end = clock();
    cout << count << endl;
    cout << end - start << "ms" << endl;
    return 0;
}
