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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int res = root->val;
        while(!q.empty()) {
            int width = q.size();
            for(int i = 0; i < width; i++) {
                TreeNode *pNode = q.front();
                q.pop();
                if(i == 0) {
                    res = pNode->val;
                }
                if(pNode->left) {
                    q.push(pNode->left);
                }
                if(pNode->right) {
                    q.push(pNode->right);
                }
            }
        }
        
        return res;
    }
};