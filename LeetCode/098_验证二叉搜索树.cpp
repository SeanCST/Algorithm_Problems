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
int *last = NULL;
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        if(isValidBST(root->left)) {
            if((last == NULL) || (last && *last < root->val)) {
                last = &root->val;
                return isValidBST(root->right);
            } 
        }

        return false;
    }
};

class Solution {
public:
    void inOrder(TreeNode *root, vector<int>& inOrderSeq) {
        if(root == NULL) {
            return;
        }

        inOrder(root->left, inOrderSeq);
        inOrderSeq.push_back(root->val);
        inOrder(root->right, inOrderSeq);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> inOrderSeq;
        inOrder(root, inOrderSeq);

        for(int i = 1; i < inOrderSeq.size(); i++) {
            if(inOrderSeq[i] <= inOrderSeq[i - 1]) {
                return false;
            }
        }

        return true;
    }
};