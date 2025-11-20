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
    public void flatten(TreeNode root) {
        while (root != null) {
            if (root.left == null) {
                root = root.right;
            } else {
                TreeNode pre = root.left;
                while (pre.right != null) {
                    pre = pre.right;
                }

                pre.right = root.right;
                root.right = root.left;
                root.left = null;
                root = root.right;
            }
        }
    }

    // public void flatten(TreeNode root) {
    //     if (root != null) {
    //         flattenTree(root);
    //     }
    // }

    // private TreeNode[] flattenTree(TreeNode root) {
    //     TreeNode tail = root;
    //     TreeNode right = root.right;

    //     if (root.left != null) {
    //         TreeNode[] leftList = flattenTree(root.left);
    //         root.right = leftList[0];
    //         tail = leftList[1];
    //         root.left = null;
    //     }

    //     if (right != null) {
    //         TreeNode[] rightList = flattenTree(right);
    //         tail.right = rightList[0];
    //         tail = rightList[1];
    //     }

    //     return new TreeNode[]{root, tail};
    // }
}