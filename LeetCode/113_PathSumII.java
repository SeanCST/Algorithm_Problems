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
    List<List<Integer>> res = new LinkedList<>();
    Deque<Integer> path = new LinkedList<>();

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return res;
        }
        dfs(root, targetSum);
        return res;
    }

    private void dfs(TreeNode root, int targetSum) {
        path.offerLast(root.val);
        if (root.left == null && root.right == null && targetSum == root.val) {
            res.add(new LinkedList<Integer>(path));
            path.pollLast();
            return;
        }

        if (root.left != null) {
            dfs(root.left, targetSum - root.val);
        }
        if (root.right != null) {
            dfs(root.right, targetSum - root.val);
        }

        path.pollLast();
    }
}