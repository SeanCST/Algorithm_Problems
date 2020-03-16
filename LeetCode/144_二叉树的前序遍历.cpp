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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        stack<TreeNode *> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode *top = stk.top();
            stk.pop();
            res.push_back(top->val);
            if(top->right != NULL) {
                stk.push(top->right);
            }
            if(top->left != NULL) {
                stk.push(top->left);
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;

        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode *pNode = s.top();
            s.pop();
            if(pNode == NULL) continue;
            res.push_back(pNode->val);

            // 先右后左，保证左子树先遍历
            if(pNode->right)
                s.push(pNode->right);
            if(pNode->left)
                s.push(pNode->left);            
        }
        
        return res;
    }
    
};