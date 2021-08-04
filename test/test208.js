//300. 最长递增子序列
var lengthOfLIS = function(arr) {
    const len = arr.length;
    if(len < 2) return len;
    const dp = new Array(len).fill(0); dp[0] = 1;

    for(let i=1; i<len; ++i){
        let max = 1;
        for(let index = i - 1; index >= 0; --index){
            if(arr[index] < arr[i]){
                max = Math.max(max, dp[index] + 1);
            }
        }
        dp[i] = max;
    }

    console.log(dp);

    return dp.reduce((pre, cur) => Math.max(pre, cur), 0);
};

let arr = [1,3,6,7,9,4,10,5,6];


console.log(lengthOfLIS(arr));
