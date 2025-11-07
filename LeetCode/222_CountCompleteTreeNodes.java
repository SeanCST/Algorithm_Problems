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
    public int countNodes(TreeNode root) {
        int hl = 0, hr = 0;
        TreeNode l = root, r = root;
        while (l != null) {
            hl += 1;
            l = l.left;
        }
        while (r != null) {
            hr += 1;
            r = r.right;
        }

        if (hl == hr) {
            return (int)Math.pow(2, hl) - 1;
        }

        return countNodes(root.left) + countNodes(root.right) + 1;
    }
}