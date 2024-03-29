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
    private List<Integer> res = new ArrayList<Integer>();

    public List<Integer> preorder(Node root) {
        if(root != null) {
            res.add(root.val);
            if(root.children != null) {
                for(Node child : root.children) {
                    preorder(child);
                }
            }
        }

        return res;
    }
}