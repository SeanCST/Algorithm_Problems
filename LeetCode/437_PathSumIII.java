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

    public int pathSum(TreeNode root, int targetSum) {
        Map<Long, Integer> map = new HashMap<>();
        map.put(0L, 1);

        return preOrder(root, targetSum, 0L, map);
    }

    private int preOrder(TreeNode root, int target, long cur, Map<Long, Integer> map) {
        if (root == null) {
            return 0;
        }
        cur += root.val;
        int res = map.getOrDefault(cur - target, 0);
        map.put(cur, map.getOrDefault(cur, 0) + 1);
        res += preOrder(root.left, target, cur, map);
        res += preOrder(root.right, target, cur, map);
        map.put(cur, map.getOrDefault(cur, 0) - 1);

        return res;
    }
}