/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution { 
    private int res = 0;

    public int sumNumbers(TreeNode root) {
        dfs(root, 0);

        return res;
    }

    private void dfs(TreeNode root, int cur) {
        cur = cur * 10 + root.val;
        if (root.left == null && root.right == null) {
            res += cur;
        }

        if (root.left != null) {
            dfs(root.left, cur);
        }

        if (root.right != null) {
            dfs(root.right, cur);
        }
    }
}