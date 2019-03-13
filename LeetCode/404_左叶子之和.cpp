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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        
        int sum = 0;
        if(root->left != NULL) {
            if(root->left->left == NULL && root->left->right == NULL) { // 左叶子结点
                sum += root->left->val;
            } else {
                sum += sumOfLeftLeaves(root->left);
            }
        }
    
        if(root->right != NULL) {
            sum += sumOfLeftLeaves(root->right);
        }
        
        return sum;
    }
};