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
private:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        traver(root);
        return root;
    }
    
    void traver(TreeNode* pNode) {
        if(pNode == NULL) return;
        traver(pNode->right);
        sum += pNode->val;
        pNode->val = sum;
        traver(pNode->left);
    }
};