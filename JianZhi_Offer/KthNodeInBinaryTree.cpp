/* 剑指 Offer - 二叉搜索树的第k个结点
 * 给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，
 * 按结点数值大小顺序第三小结点的值为4。
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
    int count = 0;·
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot != NULL) {
            TreeNode* ret = KthNode(pRoot->left, k);
            if(ret) return ret;
            if(++count == k)
                return pRoot;
            
            ret = KthNode(pRoot->right, k);
            if(ret) return ret;
        }
        
        return NULL;
    }

   
};