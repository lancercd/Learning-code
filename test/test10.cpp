#include "stdio.h"
#include "math.h"
using namespace std;

int is_pri(int num){
    if(num < 1) return 0;
    if(num ==2 || num ==3) return 1;
    if(num%6 != 1 || num%6 != 5) return 0;
    int sq = (int)sqrt(num);
    for(int i=5; i<=sq; i+=6)
    {
        if(num % i == 0 || num%(i+2) == 0) return 0;
    }
    return 1;
}

int main(){
    char str[101];
    int arr[27] = {0}, i=0;
    scanf("%s", str);
    while(str[i]!= '\0'){
        ++arr[str[i] - 'a'];
        ++i;
    }
    int max=-1, min=100;
    for(i=0; i<27; ++i){
        if(arr[i] > 0){
            if(max < arr[i]) max = arr[i];
            if(min > arr[i]) min = arr[i];
        }
    }
    is_pri(max-min)? printf("Lucky Word\n%d\n", max-min):printf("No Answer\n0\n");

    return 0;
}
