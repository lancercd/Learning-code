/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    List<Integer> list;

    public Solution(){
        list = null;
    }

    public List<Integer> preorder(Node root) {
        list = new ArrayList<>();
        dfs(root);
        return list;
    }

    public void dfs(Node node){
        if(null == node) return;
        list.add(node.val);
        for(Node ch : node.children){
            dfs(ch);
        }
    }


}
