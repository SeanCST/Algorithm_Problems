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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        q1.push(root);
        while(!q1.empty() || !q2.empty()) { // 不全为空
            vector<int> temp;
            if(!q1.empty()) {
                while(!q1.empty()) {
                    TreeNode *node = q1.front();
                    q1.pop();
                    temp.push_back(node->val);
                    if(node->left != NULL) q2.push(node->left);
                    if(node->right != NULL) q2.push(node->right);
                }
                res.push_back(temp);
                continue;
            }

            while(!q2.empty()) {
                TreeNode *node = q2.front();
                q2.pop();
                temp.push_back(node->val);
                if(node->left != NULL) q1.push(node->left);
                if(node->right != NULL) q1.push(node->right);
            }
            res.push_back(temp);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};