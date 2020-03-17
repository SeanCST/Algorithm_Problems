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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode*> stk;
        while(!stk.empty() || root != NULL) {
            if(root == NULL) {
                root = stk.top();
                stk.pop();
                res.push_back(root->val);
                root = root->right;
            } else {
                stk.push(root);
                root = root->left;
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        
        while(cur != NULL || !s.empty()) {
            while(cur) {
                s.push(cur);
                cur = cur->left;
            }
            TreeNode *pNode = s.top();
            s.pop();
            res.push_back(pNode->val);
            
            cur = pNode->right;
        }
        
        return res;
    }
};