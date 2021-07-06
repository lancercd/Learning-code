public class test191{
  public static void main(String[] args){
    ListNode head = new ListNode(1);
    head.next = new ListNode(2);
    head.next.next = new ListNode(3);
    head.next.next.next = new ListNode(4);

    ListNode newHead = reverseList(head);

    while(newHead != null){
      System.out.println(newHead.val);
      newHead = newHead.next;
    }
  }


  public static ListNode reverseList(ListNode head) {
        if(head == null) return null;
        ListNode pre = new ListNode(0);
        ListNode tmp, cur;
        while(head != null){
            tmp = pre.next;
            pre.next = head;
            cur = head.next;
            head.next = tmp;
            head = cur;

        }

        return pre.next;
    }

}


class ListNode{
  int val;
  ListNode next;
  ListNode(){}
  ListNode(int x){
    this.val = x;
  }
}
