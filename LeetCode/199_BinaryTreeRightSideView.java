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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        dfs(root, res, 0);
        return res;
    }

    private void dfs(TreeNode root, List<Integer> res, int depth) {
        if (root == null) {
            return;
        }

        if (depth == res.size()) {
            res.add(root.val);
        }
        dfs(root.right, res, depth + 1);
        dfs(root.left, res, depth + 1);
    }

    // public List<Integer> rightSideView(TreeNode root) {
    //     List<Integer> res = new ArrayList<>();
    //     Queue<TreeNode> queue = new ArrayDeque<>();
    //     if (root != null) {
    //         queue.offer(root);
    //     }
    //     TreeNode right = root;
    //     while (!queue.isEmpty()) {
    //         TreeNode cur = queue.poll();
    //         if (right == cur) {
    //             res.add(cur.val);
    //             right = null;
    //         }        
    //         if (cur.right != null) {
    //             if (right == null) {
    //                 right = cur.right;
    //             }
    //             queue.offer(cur.right);
    //         }
    //         if (cur.left != null) {
    //             if (right == null) {
    //                 right = cur.left;
    //             }
    //             queue.offer(cur.left);
    //         }
    //     }

    //     return res;
    // }
}