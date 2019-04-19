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
    TreeNode *preNode = NULL;
    int minDelta = INT_MAX;
    
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        
        return minDelta;
    }
    
    void inOrder(TreeNode* t) {
        if(t == NULL) return;
        
        inOrder(t->left);
        if(preNode != NULL)
            minDelta = min(t->val - preNode->val, minDelta);
        preNode = t;
        inOrder(t->right);
    }
};