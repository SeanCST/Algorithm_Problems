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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size()) {
            return NULL;
        }

        return build(preorder, inorder, 0, 0, preorder.size());
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preorderLeft, int inorderLeft, int len) {
        if(len == 0) {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[preorderLeft]);
        if(len == 1) {
            return root;
        }

        // find the inorder position of the first num in preorder
        int mid = inorderLeft;
        for(int i = inorderLeft; i < inorderLeft + len; i++) {
            if(preorder[preorderLeft] == inorder[i]) {
                mid = i;
                break;
            }
        }

        int leftLen = mid - inorderLeft;
        int rightLen = len - leftLen - 1;

        root->left = build(preorder, inorder, preorderLeft + 1, inorderLeft, leftLen);
        root->right = build(preorder, inorder, preorderLeft + 1 + leftLen, mid + 1, rightLen);

        return root;
    }
};