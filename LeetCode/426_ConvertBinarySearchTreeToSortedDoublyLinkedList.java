/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    public Node treeToDoublyList(Node root) {
        if (root == null) {
            return root;
        }

        Node[] pair = dfs(root);
        pair[0].left = pair[1];
        pair[1].right = pair[0];

        return pair[0];
    }

    private Node[] dfs(Node root) {
        Node first = root, last = root;
        if (root.left != null) {
            Node[] pair = dfs(root.left);
            root.left = pair[1];
            pair[1].right = root;
            first = pair[0];
        }
        if (root.right != null) {
            Node[] pair = dfs(root.right);
            root.right = pair[0];
            pair[0].left = root;
            last = pair[1];
        }

        return new Node[]{first, last};
    }
}