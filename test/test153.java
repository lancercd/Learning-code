
import java.util.Stack;

/*
        3
      /   \
     5     1
   /  \   / \
  6   2  0  8
     / \
    7  4
 */



public class test153{
    public static void main(String[] args)
    {
        Node root = build();
        prePrint(root);
        midPrint(root);
        backPrint(root);
    }

    /**
     * 先序遍历
     */
    public static void prePrint(Node root){
        System.out.println("pre");
        if( null == root) return;
        Stack<Node> stack = new Stack<>();
        stack.push(root);
        while(stack.size() != 0)
        {
            Node current = stack.pop();
            System.out.print(current.val + " ");

            if(null != current.right) stack.push(current.right);
            if(null != current.left) stack.push(current.left);
        }
        System.out.println(" ");
        System.out.println("================");
    }

    /**
     * 中序遍历
     */
    public static void midPrint(Node root)
    {
        System.out.println("mid");
        if(null == root) return;
        Stack<Node> stack = new Stack<>();
        Node current = root;
        while(stack.size() != 0 || current != null)
        {
            if(current != null)
            {
                stack.push(current);
                current = current.left;
            }else{
                current = stack.pop();
                System.out.print(current.val + " ");
                current = current.right;
            }
        }
        System.out.println("");
        System.out.println("=============");
    }

    /**
     * 后序遍历
     */
    public static void backPrint(Node pre)
    {
        System.out.println("");
        System.out.println("back");
        Stack<Node> stack = new Stack<>();
        stack.push(pre);
        Node current = null;
        while(!stack.isEmpty())
        {
            current = stack.peek();
            if(current.left != null && pre != current.left && pre != current.right)
                stack.push(current.left);
            else if(current.right != null && pre != current.right)
                stack.push(current.right);
            else{
                System.out.print(stack.pop().val + " ");
                pre = current;
            }


        }
        System.out.println("");
        System.out.println("=============");
    }


    public static Node build(){
        Node root = new Node(3);
        Node n5 = new Node(5);
        Node n1 = new Node(1);
        Node n6 = new Node(6);
        Node n2 = new Node(2);
        Node n0 = new Node(0);
        Node n8 = new Node(8);
        Node n7 = new Node(7);
        Node n4 = new Node(4);

        root.left = n5;
        root.right = n1;
        n5.left = n6;
        n5.right = n2;

        n1.left = n0;
        n1.right = n8;

        n2.left = n7;
        n2.right = n4;
        return root;
    }
}

class Node{
    public Node left;
    public Node right;
    public int val;
    public Node () {}
    public Node(int val){this.val = val;}
}
