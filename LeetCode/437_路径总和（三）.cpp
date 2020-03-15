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
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) {
            return 0;
        }

        int res = pathSumWithRoot(root, sum) +  // 以本结点为根的路径
                  pathSum(root->left, sum) + // 递归左子结点
                  pathSum(root->right, sum); // 递归右子结点

        return res;
    }

    int pathSumWithRoot(TreeNode* root, int sum) {
        if(root == NULL) {
            return 0;
        }
        int res = 0;
        if(sum == root->val) {
            res++;
        }
        // 以同一个根结点为路径开始的满足条件的数目
        res += pathSumWithRoot(root->left, sum - root->val) + 
               pathSumWithRoot(root->right, sum - root->val);

        return res;
    }
};