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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }

        return findLargerValue(root, root->val);
    }

    int findLargerValue(TreeNode* root, int val) {
        if(root == NULL) {
            return -1;
        }
        if(root->val > val) {
            return root->val;
        } else {
            int l = findLargerValue(root->left, val);
            int r = findLargerValue(root->right, val);
            if(l > -1 && r > -1) {
                return min(l, r);
            } else {
                return l == -1 ? r : l;
            }
        }
    }
};
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL || root->left == NULL) return -1;
        
        int leftVal = root->left->val;
        int rightVal = root->right->val;
        
        if(leftVal == root->val)
           leftVal = findSecondMinimumValue(root->left);
        if(rightVal == root->val)
           rightVal = findSecondMinimumValue(root->right);
            
        if(leftVal != -1 && rightVal != -1) {
            return min(leftVal, rightVal);
        } else if(leftVal != -1) {
            return leftVal;
        } else {
            return rightVal;
        }
    }
};