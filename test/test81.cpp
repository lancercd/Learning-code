#include "stdio.h"
#include "stdlib.h"

int main(){
    int num = 0; scanf("%d", &num);
    if(num > 1){
        printf("Today, I ate %d apples.", num);
        return 0;
    }
    printf("Today, I ate %d apple.", num);

    return 0;
}
