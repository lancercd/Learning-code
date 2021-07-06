/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    const len = nums.length;
    let l = 0, r =  len + 1, mid = 0, ans = 0;
    while(l <= r){
        mid = l + ((r - l) >> 1);
        // if(nums[mid] != mid) return mid;
        if(nums[mid] == mid){
            l = mid + 1;
        }else{
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
};

const arr = [0,1,2,3,4,5,6,7,9];

console.log(missingNumber(arr));
