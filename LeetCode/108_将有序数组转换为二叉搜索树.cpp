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
    TreeNode* buildBST(vector<int>& nums, int l, int r) {
        if (l <= r) {
            int mid = (l + r) / 2;
            TreeNode *p = new TreeNode(nums[mid]);
            p->left = buildBST(nums, l, mid - 1);
            p->right = buildBST(nums, mid + 1, r);
            return p;
        }
        return NULL;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;

        return buildBST(nums, 0, nums.size() - 1);
    }
};