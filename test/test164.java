import java.util.Stack;

public class test164{
    public static void main(String[] args){
        MinStack stack = new MinStack();
        stack.push(-2);
        stack.push(0);
        stack.push(-3);

        System.out.println(stack.min());
        stack.pop();
        System.out.println(stack.top());
        System.out.println(stack.min());

    }
}


class MinStack {
    private Stack<Integer> A;
    private Stack<Integer> B;
    /** initialize your data structure here. */
    public MinStack() {
        this.A = new Stack<>();
        this.B = new Stack<>();
    }

    public void push(int x) {
        A.push(x);
        if(B.isEmpty() || B.peek() >= x){
            B.push(x);
        }
    }

    public void pop() {
        if(A.pop().equals(B.peek())) B.pop();
    }

    public int top() {
        return A.peek();
    }

    public int min() {
        return B.peek();
    }
}
