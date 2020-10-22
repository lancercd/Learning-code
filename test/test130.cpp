#include "stdio.h"

int maxSubArray(int* nums, int numsSize){
    int ans = 0;
    register int i = 0;
    if(numsSize  < 2) return nums[0];
    for(i=1; i<numsSize; ++i)
    {
        if(nums[i - 1] < 1) continue;
        nums[i] += nums[i-1];
    }

    ans = nums[0];
    for(i=1; i<numsSize; ++i)
    {
        if(nums[i] > ans) ans = nums[i];
    }
    return ans;
}

int main(){
    const int SIZE = 9;
    int arr[SIZE] = {-2,1,-3,4,-1,2,1,-5,4};

    printf("%d", maxSubArray(arr, SIZE));


    return 0;
}
