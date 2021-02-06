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
    int xpar, ypar, xdep, ydep;

    public boolean isCousins(TreeNode root, int x, int y) {
        dfs(root.left, x, y, 1, root.val);
        dfs(root.right, x, y, 1, root.val);

        return (xpar != ypar) && (xdep == ydep);
    }

    public void dfs(TreeNode root, int x, int y, int dep, int par) {
        if(root == null) {
            return;
        }
        if(root.val == x) {
            xpar = par;
            xdep = dep;
        } else if (root.val == y) {
            ypar = par;
            ydep = dep;
        } else {
            dfs(root.left, x, y, dep + 1, root.val);
            dfs(root.right, x, y, dep + 1, root.val);
        }
    }
}