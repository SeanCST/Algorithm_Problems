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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL) return false;
        return isSubtreeWithRoot(s, t) || 
            isSubtree(s->left, t) || 
            isSubtree(s->right, t);
    }
    
    bool isSubtreeWithRoot(TreeNode* s, TreeNode* t) {
        if(t == NULL && s == NULL) return true;
        if(t == NULL || s == NULL) return false;
        if(s->val != t->val) return false;
        
        return isSubtreeWithRoot(s->left, t->left) && isSubtreeWithRoot(s->right, t->right);
    }
};