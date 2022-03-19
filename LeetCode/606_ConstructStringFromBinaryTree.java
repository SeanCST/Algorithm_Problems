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
    public String tree2str(TreeNode root) {
        if(root == null) {
            return "";
        }

        String res = "";
        res += root.val;

        if(root.left == null && root.right != null) {
            res += "()";
        } else if(root.left != null) {
            res += "(";
            res += tree2str(root.left);
            res += ")";
        }

        if(root.right != null) {
            res += "(";
            res += tree2str(root.right);
            res += ")";
        }


        return res;
    }
}