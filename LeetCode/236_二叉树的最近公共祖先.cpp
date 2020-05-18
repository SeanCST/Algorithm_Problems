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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if(left == NULL && right == NULL) 
            return NULL;
        else if(left != NULL && right != NULL)
            return root;
        else
            return left != NULL ? left : right;
    }   
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) {
            return root;
        }
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if(left != NULL && right != NULL) {
            return root;
        }

        return left != NULL ? left : right;
    }
};


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
    bool foundNode(TreeNode* root, TreeNode* node) {
        if(root == NULL) {
            return false;
        } else if(root == node) {
            return true;
        } else {
            return foundNode(root->left, node) || foundNode(root->right, node);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p) {
            return p;
        }
        if(root == q) {
            return q;
        }
        
        bool pFoundedOnLeft = foundNode(root->left, p);
        bool qFoundedOnLeft = foundNode(root->left, q);
        if(pFoundedOnLeft != qFoundedOnLeft) { // 一个在左边一个在右边
            return root;
        } else if(pFoundedOnLeft && qFoundedOnLeft) { // 都在左边
            return lowestCommonAncestor(root->left, p, q);
        } else { // 都在右边
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};