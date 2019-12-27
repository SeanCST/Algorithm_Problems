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
        vector<string> pathRes;
        
        if(root == NULL) {
            return pathRes;
        }

        vector<int> curPath;
        paths(root, pathRes, curPath);
        
        return pathRes;
    }
    
    void paths(TreeNode* root, vector<string>& pathRes, vector<int>& curPath) {
        if(root == NULL) {
            return;
        }
        curPath.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            pathRes.push_back(buildPath(curPath));
        } else {
             paths(root->left, pathRes, curPath);
             paths(root->right, pathRes, curPath);
        }
        curPath.pop_back();
    }

    string buildPath(vector<int> curPath) {
        string path;
        for(int j = 0; j < curPath.size(); j++) {
            if(j == 0){
                path += to_string(curPath[j]);
            } else {
                path += "->";
                path += to_string(curPath[j]);
            }
        }

        return path;
    }
};