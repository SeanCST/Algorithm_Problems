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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return isLeftRightSymmetric(root->left, root->right);
    }

    bool isLeftRightSymmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        } else if (left == NULL || right == NULL) {
             return false;
        } 
        
        return  (left->val == right->val) && isLeftRightSymmetric(left->left, right->right) && isLeftRightSymmetric(left->right, right->left);
        
        
    }
};