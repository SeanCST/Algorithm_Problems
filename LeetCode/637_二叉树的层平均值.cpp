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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root == NULL) return res;
        
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            double levelSum = 0;
            int cnt = q.size();
            for(int i = 0; i < cnt; i++) {
                TreeNode *pNode = q.front();
                q.pop();
                levelSum += pNode->val;
                if(pNode->left != NULL) {
                    q.push(pNode->left);
                }
                if(pNode->right != NULL) {
                    q.push(pNode->right);
                }
            }
            
            res.push_back(levelSum / cnt);
        }
        
        return res;
    }
};