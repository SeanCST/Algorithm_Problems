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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> res;
        vector<string> pathRes;
        if(root == NULL) return pathRes;

        vector<int> curPath;
        curPath.push_back(root->val);
        paths(root, res, curPath);
        
        for(int i = 0; i < res.size(); i++) {
            string path;
            for(int j = 0; j < res[i].size(); j++) {
                if(j == 0)
                    path += to_string(res[i][j]);
                else {
                    path += "->";
                    path += to_string(res[i][j]);
                }
            }
            pathRes.push_back(path);
            path = "";
        }
        
        return pathRes;
    }
    
    void paths(TreeNode* root, vector<vector<int>>& res, vector<int>& curPath) {
        if(root->left == NULL && root->right == NULL) {
            res.push_back(curPath);
            return;
        }
        
        if(root->left != NULL) {
            // 左孩子不为空，将左孩子加入到路径中
            curPath.push_back(root->left->val);
            // 递归左孩子
            paths(root->left, res, curPath);
            // 左孩子路径已完成，删除左孩子字符
            curPath.pop_back();
        }
        
        if(root->right != NULL) {
            // 右孩子不为空，将左孩子加入到路径中
            curPath.push_back(root->right->val);
            // 递归右孩子
            paths(root->right, res, curPath);
            // 右孩子路径已完成，删除右孩子字符
            curPath.pop_back();
        }
        
        
    }
};