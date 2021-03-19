import java.util.Stack;

public class test187{
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5};
        int left = 2;
        int right = 4;

        Solution solution = new Solution();
        ListNode head = solution.reverseBetween(getNode(arr), left, right);
        print(head);
    }
    public static ListNode getNode(int[] arr){
        ListNode pre_head = new ListNode(-501);
        ListNode tmp = pre_head;
        for(int i=0; i<arr.length; ++i){
            tmp.next = new ListNode(arr[i]);
            tmp = tmp.next;
        }
        return pre_head.next;
    }

    public static void print(ListNode head){
        while(head != null){
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }
}


class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        int index = 1;
        ListNode pre_head = new ListNode(-500);
        pre_head.next = head;
        Stack<ListNode> stack = new Stack<>();
        ListNode pre = pre_head, end = pre_head;
        while(pre.next != null && index < left){
            ++index;
            pre = pre.next;
        }
        end = pre.next;
        while(end != null && index <= right){
            ++index;
            stack.push(end);
            end = end.next;
        }
        while(!stack.isEmpty()){
            pre.next = stack.pop();
            pre = pre.next;
        }
        pre.next = end;

        return pre_head.next;
    }
}

class ListNode {
     int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }
