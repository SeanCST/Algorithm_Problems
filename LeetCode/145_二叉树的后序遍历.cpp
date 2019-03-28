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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *preNode = root;
        while(!s.empty()) {
            TreeNode *pNode = s.top();
            s.pop();
            res.push_back(pNode->val);
            if(pNode->left)
                s.push(pNode->left);
            if(pNode->right)
                s.push(pNode->right);   
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};