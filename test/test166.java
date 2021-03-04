import java.util.Stack;

public class test166{
    public static void main(String[] args) {
        int[] arrA = {1,5,3,4,8};
        int[] arrB = {3,4,8,5,1};
        System.out.println(new Solution().validateStackSequences(arrA, arrB));
    }
}


class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int len = len = pushed.length;
        if(len == 1) return true;
        Stack<Integer> stack = new Stack<>();
        int B = 0;
        for(int num : pushed){
            stack.push(num);
            while(!stack.isEmpty() && stack.peek() == popped[B]){
                ++B;
                stack.pop();
            }
        }
        return stack.isEmpty();
    }
}
