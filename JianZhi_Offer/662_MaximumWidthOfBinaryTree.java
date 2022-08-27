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
    Map<Integer, Integer> levelMinIndex = new HashMap<>();

    public int widthOfBinaryTree(TreeNode root) {
        return dfs(root, 1, 1);
    }

    private int dfs(TreeNode node, int index, int depth) {
        if(node == null) {
            return 0;
        }

        levelMinIndex.putIfAbsent(depth, index);
        return Math.max(index - levelMinIndex.get(depth) + 1,
                        Math.max(dfs(node.left, index * 2, depth + 1), 
                                 dfs(node.right, index * 2 + 1, depth + 1)));
    }
}