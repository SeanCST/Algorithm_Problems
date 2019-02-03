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
    int height(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + max(height(node->left), height(node->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        int leftH = height(root->left);
        int rightH = height(root->right);
        
        return (leftH - rightH <= 1) && (leftH - rightH >= -1) && isBalanced(root->left) && isBalanced(root->right);
    }
};