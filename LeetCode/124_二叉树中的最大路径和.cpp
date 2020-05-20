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
private:
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        maxChildPath(root);
        return res;
    }

    int maxChildPath(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }

        int leftMax = max(0, maxChildPath(root->left));
        int rightMax = max(0, maxChildPath(root->right));        
        res = max(root->val + leftMax + rightMax, res);

        return root->val + max(leftMax, rightMax);
    }
};