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
    int height(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        int l = height(node->left);
        if(l == -1) {
            return -1;
        }
        int r = height(node->right);
        if(r == -1) {
            return -1;
        }
        return abs(l - r) > 1 ? -1 : max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

class Solution {
public:
    bool res = true;

    int maxDepth(TreeNode *node) {
        if(node == NULL) return 0;
        int l = maxDepth(node->left);
        int r = maxDepth(node->right);
        if(abs(l - r) > 1) 
            res = false;
        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return res;
    }
};

class Solution {
public:
    int height(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + max(height(node->left), height(node->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        int leftH = height(root->left);
        int rightH = height(root->right);
        
        return (leftH - rightH <= 1) && (leftH - rightH >= -1) && isBalanced(root->left) && isBalanced(root->right);
    }
};