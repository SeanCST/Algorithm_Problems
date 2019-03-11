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
    int res = 0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        maxDepth(root);
        
        return res; 
    }
    
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int leftLongest = maxDepth(root->left);
        int rightLongest = maxDepth(root->right);
        
        res = max(res, leftLongest + rightLongest);

        return max(leftLongest, rightLongest) + 1;
    }
};