/* 剑指 Offer - 重建二叉树

 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
 * 则重建二叉树并返回。
 **/

 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0 || vin.size() == 0)
            return NULL;
        TreeNode* pNode = new TreeNode(pre[0]);
        int i = 0;
        // 找到根节点在中序遍历序列中的的位置
        while(vin[i] != pre[0])
            i++;
        if(i > 0){
            pNode->left = Constructing(pre, 1, i, vin, 0, i - 1);
        } else {
            pNode->left = NULL;
        }
        if(i < vin.size() - 1){
            pNode->right = Constructing(pre, i + 1, vin.size() - 1, vin, i + 1, vin.size() - 1);
        } else {
            pNode->right = NULL;
        }

        return pNode;
    }
private:
    TreeNode* Constructing(vector<int>& pre, unsigned long pl, unsigned long pr, vector<int>& vin, unsigned long vl, unsigned long vr) {
        TreeNode* pNode = new TreeNode(pre[pl]);
        if(pl == pr)
            return pNode;
        unsigned long i = vl;
        // 找到根节点在中序遍历序列中的的位置
        while(vin[i] != pre[pl])
            i++;
        if(i > vl){
            pNode->left = Constructing(pre, pl + 1, pl + i - vl, vin, vl, i - 1);  // i-vl + pl +
        } else {
            pNode->left = NULL;
        }

        if(i < vr){
            pNode->right = Constructing(pre, pr - vr + i + 1, pr, vin, i + 1, vr);
        } else {
            pNode->right = NULL;
        }

        return pNode;
    }
};