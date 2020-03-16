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
    int maxLen = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        bfs(root);
        return maxLen;
    }

    int bfs(TreeNode *root) {
        // 递归返回条件
        if(root == NULL) {
            return 0;
        }

        // 递归搜索
        int l = bfs(root->left);
        int r = bfs(root->right);

        // 合并子问题
        int leftLen = 0, rightLen = 0;
        if(root->left != NULL && root->left->val == root->val) {
            leftLen = l + 1;
        }
        if(root->right != NULL && root->right->val == root->val) {
            rightLen = r + 1;
        }

        maxLen = max(maxLen, leftLen + rightLen); // 关键 ： 更新 maxLen
        // 只需返回左边或右边路径最长即可，若不与当前 root 相等，则为0
        return max(leftLen, rightLen); 
    }
};

class Solution {
public:
    int path = 0;
        
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return path;
    }
    
    int dfs(TreeNode* root) {
        if(root == NULL) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int leftPath = root->left != NULL && root->val == root->left->val ? left + 1 : 0;
        int rightPath = root->right != NULL && root->val == root->right->val ? right + 1 : 0;
        path = max(path, leftPath + rightPath);
        
        return max(leftPath, rightPath);
    }
};