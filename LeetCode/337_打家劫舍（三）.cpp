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