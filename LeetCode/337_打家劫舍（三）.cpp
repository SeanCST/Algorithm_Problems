/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        
        // 偷
        int rob_money = root->val;
        if(root->left != NULL) {
            rob_money += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right != NULL) {
            rob_money += rob(root->right->left) + rob(root->right->right);
        }
        // 不偷
        int noRob_money = rob(root->left) + rob(root->right);
        
        return max(rob_money, noRob_money);
    }
};

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

    private Map<TreeNode, Integer> map = new HashMap<TreeNode, Integer>();

    public int rob(TreeNode root) {

        if(root == null) {
            return 0;
        }

        if(map.containsKey(root)) {
            return map.get(root);
        }

        int res = root.val;
        if(root.left != null) {
            res += rob(root.left.left) + rob(root.left.right);
        }
        if(root.right != null) {
            res += rob(root.right.left) + rob(root.right.right);
        }

        res = Math.max(res, rob(root.left) + rob(root.right));
        map.put(root, res);
        return res;
    }
}