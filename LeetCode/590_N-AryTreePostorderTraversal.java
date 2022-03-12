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

    public List<Integer> postorder(Node root) {
        if(root != null) {
            for(Node child : root.children) {
                postorder(child);
            }
            res.add(root.val);
        }

        return res;
    }
}