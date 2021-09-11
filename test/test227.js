const arr = [2, 1, 2, 4, 3];

// 单调栈
// Tag leetcode 单调栈模板(js)
// 单调栈模板

function nextGreaterElement(arr) {
    const len = arr.length;
    const ans = new Array(len), stack = [];

    for (let i = len - 1; i > -1; --i) {
        while(stack.length !==0 && stack[stack.length - 1] <= arr[i]) stack.pop();

        ans[i] = (stack.length === 0)? -1 : stack[stack.length - 1];
        stack.push(arr[i]);
    }
    return ans;
}

console.log(nextGreaterElement(arr));
