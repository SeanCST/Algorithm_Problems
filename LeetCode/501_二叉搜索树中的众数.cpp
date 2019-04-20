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
    int maxCount = 0;
    int curCount = 0;
    TreeNode *preNode = NULL;
    vector<int> res;
    
    vector<int> findMode(TreeNode* root) {
        if(root == NULL) return res;
        inOrder(root);
        
        return res;
    }
    
    void inOrder(TreeNode* t) {
        if(t == NULL) return;
        inOrder(t->left);
        
        if(preNode != NULL && t->val == preNode->val) {
            curCount++;
        } else {
            curCount = 1;
        }
        preNode = t;
        
        if(curCount > maxCount) {
            res.clear();
            res.push_back(t->val);
            maxCount = curCount;
        } else if(curCount == maxCount) {
            res.push_back(t->val);
        }

        inOrder(t->right);
    }
};