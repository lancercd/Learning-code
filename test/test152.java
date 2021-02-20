
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class test152 {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(6);
        TreeNode n2 = new TreeNode(2);
        TreeNode n8 = new TreeNode(8);
        TreeNode n0 = new TreeNode(0);
        TreeNode n4 = new TreeNode(4);
        TreeNode n7 = new TreeNode(7);
        TreeNode n9 = new TreeNode(9);
        TreeNode n3 = new TreeNode(3);
        TreeNode n5 = new TreeNode(5);

        root.left = n2;
        root.right = n8;
        n2.left = n0;
        n2.right = n4;

        n8.left = n7;
        n8.right = n9;

        n4.left = n3;
        n4.right = n5;

        test152 test = new test152();


        TreeNode node = test.lowestCommonAncestor(root, n2, n4);
        System.out.println(node);
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode ans = null;
        Stack<TreeNode> p_path = new Stack<>();
        Stack<TreeNode> q_path = new Stack<>();
        dfs(root, p, p_path);
        dfs(root, q, q_path);

        while(p_path.size() != q_path.size()){
            if(p_path.size() > q_path.size()) p_path.pop();
            else q_path.pop();
        }

        while (true) {
            ans = p_path.pop();
            if(ans == q_path.pop()) break;
        }

        return ans;
    }

    public boolean dfs(TreeNode node, TreeNode target, Stack<TreeNode> stack){
        if(null == node) return false;
        stack.push(node);
        if(node == target) return true;
        if(dfs(node.left, target, stack) || dfs(node.right, target, stack))return true;
        stack.pop();
        return false;
    }




}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
