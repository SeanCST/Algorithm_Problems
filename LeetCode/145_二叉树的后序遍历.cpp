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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }

        stack<TreeNode *> stk;
        stk.push(root);
        TreeNode *lastPopNode = root; // 最近一次打印并弹出的节点，初始值设为 root，避免设为 NULL 导致下面的判断不准确
        while(!stk.empty()) {
            TreeNode *topNode = stk.top();
            if(topNode->left != NULL && topNode->left != lastPopNode && topNode->right != lastPopNode) {
                stk.push(topNode->left);
            } else if (topNode->right != NULL && topNode->right!= lastPopNode) {
                stk.push(topNode->right);
            } else {
                res.push_back(topNode->val);
                stk.pop();
                lastPopNode = topNode;
            }
        }
        
        return res;
    }
};

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if(root == NULL) {
//             return res;
//         }

//         stack<TreeNode *> s1;
//         s1.push(root);
//         while(!s1.empty()) {
//             TreeNode *top = s1.top();
//             s1.pop();
//             res.push_back(top->val);
//             if(top->left != NULL) {
//                 s1.push(top->left);
//             }
//             if(top->right != NULL) {
//                 s1.push(top->right);
//             }
//         }
        
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *preNode = root;
        while(!s.empty()) {
            TreeNode *pNode = s.top();
            s.pop();
            res.push_back(pNode->val);
            if(pNode->left)
                s.push(pNode->left);
            if(pNode->right)
                s.push(pNode->right);   
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};