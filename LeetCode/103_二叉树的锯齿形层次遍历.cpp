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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> s1, s2;
        vector<vector<int>> res;
        if(!root) return res;
        
        s1.push(root);
        bool even = false;
        while(!s1.empty() || !s2.empty()) {
            vector<int> r;
            if(!even) { // 奇数层
                while(!s1.empty()) {
                    TreeNode* tNode = s1.top();
                    r.push_back(tNode->val);
                    s1.pop();
                    // 孩子从左到右入栈
                    if(tNode->left) {
                        s2.push(tNode->left);
                    }
                    if(tNode->right) {
                        s2.push(tNode->right);
                    }
                }
                res.push_back(r);
                
            } else { // 偶数层
                while(!s2.empty()) {
                    TreeNode* tNode = s2.top();
                    r.push_back(tNode->val);
                    s2.pop();
                    // 孩子从右到左入栈
                    if(tNode->right) {
                        s1.push(tNode->right);
                    }
                    if(tNode->left) {
                        s1.push(tNode->left);
                    }
                }
                res.push_back(r);
            }
            
            even = !even;
        }
        
        return res;
    }
};