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
    int ans = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return ans;
    }

    int maxPath(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }

        int left = max(0, maxPath(root->left));
        int right = max(0, maxPath(root->right));
        ans = max(ans, left + right + root->val);

        return max(left, right) + root->val;
    }
};