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
    public List<List<String>> printTree(TreeNode root) {
        int height = height(root) - 1;
        int m = height + 1;
        int n = (1 << (height + 1)) - 1;
        int matrix[][] = new int[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(matrix[i], 100);
        }
        traverse(root, 0, (n - 1) / 2, matrix, height);

        List<List<String>> res = new ArrayList<>();
        for(int i = 0; i < m; i++) {
            List<String> cur = new ArrayList<>();
            for(int j = 0; j < n; j++) {
                String str = "";
                if(matrix[i][j] != 100) {
                    str += matrix[i][j];
                }
                cur.add(str);
            }
            res.add(cur);
        }

        return res;
    }

    private void traverse(TreeNode root, int r, int c, int[][] matrix, int h) {
        matrix[r][c] = root.val;
        if(root.left != null) {
            traverse(root.left, r + 1, c - (1 << (h - r - 1)), matrix, h);
        }
        if(root.right != null) {
            traverse(root.right, r + 1, c + (1 << (h - r - 1)), matrix, h);
        }
    }

    private int height(TreeNode root) {
        if(root == null) {
            return 0;
        }
        return Math.max(height(root.left), height(root.right)) + 1;
    }
}