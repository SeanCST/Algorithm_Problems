/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        } else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if(root->left == NULL && root->right == NULL) {
                return NULL;
            } else if(root->left != NULL && root->right == NULL) {
                return root->left;
            } else if(root->left == NULL && root->right != NULL) {
                return root->right;
            } else {
                TreeNode *temp = root->right;
                while(temp->left != NULL) {
                    temp = temp->left;
                }
                root->val = temp->val;
                root->right = deleteNode(root->right, root->val);
            }
        }

        return root;
    }
};



class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *cur = root;
        TreeNode *toDeleteNode = NULL;
        TreeNode *toDeleteNodeParent = NULL;

        // Find the node
        if(root == NULL) {
            return root;
        } else if(root->val == key) {
            toDeleteNode = cur;
        } else {
            while(cur != NULL) {
                if(cur->val > key && cur->left != NULL) {
                    if(cur->left->val == key) {
                        toDeleteNode = cur->left;
                        toDeleteNodeParent = cur;
                    }
                    cur = cur->left;
                } else if(cur->val < key && cur->right != NULL) {
                    if(cur->right->val == key) {
                        toDeleteNode = cur->right;
                        toDeleteNodeParent = cur;
                    }
                    cur = cur->right;
                } else {
                    break;
                }
            }
        }

        TreeNode *deletedResult = NULL;
        // Delete the node
        if(toDeleteNode == NULL) {
            return root;
        } else {
            if(toDeleteNode->left == NULL && toDeleteNode->right == NULL) {
                deletedResult = NULL;
            } else if(toDeleteNode->left != NULL && toDeleteNode->right != NULL) {
                // find the rightest node of the left child
                TreeNode *node = toDeleteNode->left;
                TreeNode *rightestParent = NULL;
                while(node->right != NULL) {
                    rightestParent = node;
                    node = node->right;
                }

                deletedResult = node;
                if(rightestParent != NULL) {
                    rightestParent->right = node->left;
                    deletedResult->left = toDeleteNode->left;
                    deletedResult->right = toDeleteNode->right;
                } else {
                    deletedResult->right = toDeleteNode->right;
                }
                
                if (toDeleteNode->left != deletedResult) {
                    deletedResult->left = toDeleteNode->left;
                }
            } else if(toDeleteNode->left != NULL && toDeleteNode->right == NULL) {
                deletedResult = toDeleteNode->left;
            } else {
                deletedResult = toDeleteNode->right;
            }
        }

        if(toDeleteNodeParent == NULL) {
            return deletedResult;
        } else {
            if(toDeleteNodeParent->left == toDeleteNode) {
                toDeleteNodeParent->left = deletedResult;
            } else {
                toDeleteNodeParent->right = deletedResult;
            }
            delete(toDeleteNode);

            return root;
        }
    }
};