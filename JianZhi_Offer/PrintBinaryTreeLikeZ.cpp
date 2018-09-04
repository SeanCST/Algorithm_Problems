/* 剑指 Offer - 按之字形顺序打印二叉树
 
 * 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
 * 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
 **/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        // 层次遍历
        stack <TreeNode*> s1, s2;
        s1.push(pRoot);
        vector<vector<int> > vec;
        if(!pRoot) return vec;

        bool even = false;
        while(!s1.empty() || !s2.empty()) {
            if(!even) {
                vector <int> r;
                while(!s1.empty()) {
                    TreeNode *pNode = s1.top();
                    s1.pop();
                    r.push_back(pNode->val);
                    // 奇数层，先保存左结点再保存右结点
                    if(pNode->left != NULL) s2.push(pNode->left);
                    if(pNode->right != NULL) s2.push(pNode->right);
                }
                vec.push_back(r);
            } else {
                vector <int> r;
                while(!s2.empty()) {
                    TreeNode *pNode = s2.top();
                    s2.pop();
                    r.push_back(pNode->val);
                    // 偶数层，先保存右结点再保存左结点
                    if(pNode->right != NULL) s1.push(pNode->right);
                    if(pNode->left != NULL) s1.push(pNode->left);
               }
                vec.push_back(r);
            }
            
            even = !even;
        }
        
        return vec;
    }
};