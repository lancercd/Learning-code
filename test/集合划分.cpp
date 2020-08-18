#include "stdio.h"
typedef unsigned long long ull;
ull S(int n){
    ull a=1, b=2, count = 1;
    if(n < 3){
        count = (n==2)? 2:1;
    }
    while(n > 2){
        count = a + b;
        a = b;
        b = count;
        --n;
    }
    return count;
}

int main(){
    int n;
    ull count = 0;
    scanf("%d", &n);
    printf("%d", S(n));
    return 0;
}
