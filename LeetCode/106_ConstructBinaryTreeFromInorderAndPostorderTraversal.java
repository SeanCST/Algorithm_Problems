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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return buildTree(inorder, postorder, 0, inorder.length - 1, 0, postorder.length - 1);
    }

    private TreeNode buildTree(int[] inorder, int[] postorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd) {
        if (inorderStart > inorderEnd) {
            return null;
        }

        int rootVal = postorder[postorderEnd];
        int rootIndexInInorder = -1, leftLen = -1;
        for (int i = inorderStart; i <= inorderEnd; i++) {
            if (inorder[i] == rootVal) {
                rootIndexInInorder = i;
                leftLen = i - inorderStart;
                break;
            }
        }

        TreeNode root = new TreeNode(rootVal);
        root.left = buildTree(inorder, postorder, inorderStart, rootIndexInInorder - 1, postorderStart, postorderStart + leftLen - 1);
        root.right = buildTree(inorder, postorder, rootIndexInInorder + 1, inorderEnd, postorderStart + leftLen, postorderEnd - 1);

        return root;
    }
}