import java.util.*;

public class test165{
    public static void main(String[] args){
        MinStack stack = new MinStack();
        stack.push(-2);
        stack.pop();
        stack.push(-2);
        System.out.println(stack.min());
        stack.push(0);
        System.out.println(stack.min());
        stack.push(0);
        stack.push(-3);
        System.out.println(stack.min());
        stack.pop();
        stack.pop();
        stack.push(-3);

        stack.pop();
        System.out.println(stack.min());
        stack.pop();
        stack.push(-5);
        stack.pop();
        System.out.println(stack.top());
        System.out.println(stack.min());

    }
}


class MinStack {
    int[] stack;
    int maxLength = 40000;
    int top;
    int min;

    /** initialize your data structure here. */
    public MinStack() {
        stack = new int[maxLength];
        top = -1;
        min = Integer.MAX_VALUE;
    }

    public void push(int x) {
        if(x <= min){
            stack[++top] = min;
            min = x;
        }
        stack[++top] = x;
    }

    public void pop() {
        if(top < 0) return;
        if(min == stack[top]){
            --top;
            min = stack[top];
        }
        --top;
    }

    public int top() {
        if(top < 0) return -1;
        return stack[top];
    }

    public int min() {
        if(top < 0) return -1;
        return min;
    }
}
