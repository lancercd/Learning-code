#include "stdio.h"




int singleNumber(int* nums, int numsSize){
    register int ans = 0, i=0;
    while(i < numsSize){
        ans ^= nums[i];
        ++i;
    }
    return ans;
}


int main() {
    int arr[5] = {4,1,2,1,2};
    printf("%d", singleNumber(arr, 5));

    return 0;
}
