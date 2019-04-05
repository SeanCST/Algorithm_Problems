/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 中序遍历法
class Solution {
private:
    int cur = 0;
    int res;
public:
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return res;
    }
    
    void inOrder(TreeNode* root, int k) {
        if(root == NULL) return;        
        if(root->left)
            inOrder(root->left, k);
        cur++;
        if(cur == k) {
            res = root->val;
            return;
        }
        if(root->right)
            inOrder(root->right, k);
    }
};

// 递归法
class Solution {
private:
    int cur = 0;
    int res;
public:
    int kthSmallest(TreeNode* root, int k) {
        int left = count(root->left);
        if(left == k - 1) return root->val;
        else if(left > k - 1)
            return kthSmallest(root->left, k);
        else
            return kthSmallest(root->right, k - left - 1);
    }
    
    int count(TreeNode* pNode) {
        if(pNode == NULL) return 0;
        return count(pNode->left) + count(pNode->right) + 1; 
    }
};