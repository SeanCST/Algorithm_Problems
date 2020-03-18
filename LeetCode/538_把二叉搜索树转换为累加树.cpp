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
    TreeNode* convertBST(TreeNode* root) {
        inOrder(root, 0);
        return root;
    }

    int inOrder(TreeNode* root, int curSum) {
        if(root == NULL) {
            return curSum;
        }
        int sum = inOrder(root->right, curSum);
        root->val = root->val + sum;
        sum = inOrder(root->left, root->val);

        return sum;
    }
};

class Solution {
private:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        traver(root);
        return root;
    }
    
    void traver(TreeNode* pNode) {
        if(pNode == NULL) return;
        traver(pNode->right);
        sum += pNode->val;
        pNode->val = sum;
        traver(pNode->left);
    }
};