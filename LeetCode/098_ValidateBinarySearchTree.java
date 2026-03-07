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
    private boolean ans = true;
    private Integer cur = null;

    public boolean isValidBST(TreeNode root) {
        inorder(root);
        return ans;
    }

    private void inorder(TreeNode node) {
        if (node.left != null) {
            inorder(node.left);
        }

        if (cur != null && cur >= node.val) {
            ans = false;
        }
        cur = node.val;

        if (node.right != null) {
            inorder(node.right);
        }
    }
}