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
    public boolean isUnivalTree(TreeNode root) {
        if(root == null) {
            return true;
        }
        return isUnival(root, root.val);
    }

    private boolean isUnival(TreeNode root, int val) {
        if(root == null) {
            return true;
        }
        boolean isLeftUnival = root.left == null ? true : root.left.val == val;
        isLeftUnival = isLeftUnival && isUnival(root.left, val);
        boolean isRightUnival = root.right == null ? true : root.right.val == val;
        isRightUnival = isRightUnival && isUnival(root.right, val);

        return isLeftUnival && isRightUnival;
    }
}