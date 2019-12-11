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
    vector<TreeNode *> generateTrees(int n) {
        if(n == 0) {
            vector<TreeNode *> all_trees;
            return all_trees;
        } 
        return generate_trees(1, n);
    }

    vector<TreeNode *> generate_trees(int start, int end) {
        vector<TreeNode *> all_trees;
        if(start > end) {
            all_trees.push_back(NULL);
            return all_trees;
        }

        for(int i = start; i <= end; i++) {
            // 左子树
            vector<TreeNode *> leftNodes = generate_trees(start, i - 1);
            // 右子树
            vector<TreeNode *> rightNodes = generate_trees(i + 1, end);
            for(TreeNode *leftNode : leftNodes) {
                for(TreeNode *rightNode : rightNodes) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    all_trees.push_back(root);
                }
            }
        }

        return all_trees;
    }
};