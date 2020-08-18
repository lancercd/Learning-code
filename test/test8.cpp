#include "stdio.h"

bool C(int n){
    
    return true;
}

int main(){
    for(int i=10000; i<100000; ++i)
    {
        if(C(i)) printf("%d ", i);
    }
    return 0;
}
