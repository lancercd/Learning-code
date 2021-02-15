
public class test151{
    public static void main(String[] args)
    {
        Node head = createNodeList();
        print(head);
        System.out.println("  ");
        print(reverseNodeList(head));
    }


    public static Node reverseNodeList(Node head){
        Node pre = null, next = null;
        while(null != head)
        {
            next = head.next;
            head.next = pre;
            pre = head;
            head = next;
        }

        return pre;
    }

    public static Node createNodeList(){
        Node head = new Node(0), tmp = head;
        for(int i=0; i<10; ++i)
        {
            tmp.next = new Node(i+1);
            tmp = tmp.next;
        }
        return head;
    }

    public static void print(Node head)
    {
        Node node = head;
        while(null != node)
        {
            p(node.data);
            node = node.next;
        }
    }
    public static void p(int num)
    {
        System.out.print(" " + num);
    }
    public static void print(String str)
    {
        System.out.print(str);
    }
}

class Node{
    public Node next;
    public int data;

    public Node(){}
    public Node(int num){
        this.data = num;
    }
}
