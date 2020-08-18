#include <stdio.h>

int main(){
    int num;
    double count=0.0;
    scanf("%d", &num);
    if(num <= 150) count += num*0.4463;
    else if(num <= 400) count += 150 * 0.4463 + (num-150) * 0.4663;
    else count += 150 * 0.4463 + 250 * 0.4663 + (num-400) * 0.5663;
    printf("%.1lf", count);
    return 0;
}
