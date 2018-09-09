/* 剑指 Offer - 树的子结构

 * 输入两棵二叉树A，B，判断B是不是A的子结构。
 *（ps：我们约定空树不是任意一个树的子结构）
 **/

 /*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;

        if (pRoot1 != NULL && pRoot2 != NULL) {
            if (pRoot1->val == pRoot2->val) {
                result = DoesTree1HaveTree2(pRoot1, pRoot2);
            }
            if (!result) {
                result = HasSubtree(pRoot1->left, pRoot2);
            }
            if (!result) {
                result = HasSubtree(pRoot1->right, pRoot2);
            }
        }

        return result;
    }
    
    bool DoesTree1HaveTree2(TreeNode *pNode1, TreeNode *pNode2) {
        if(pNode2 == NULL) return true;
        if(pNode1 == NULL) return false;

        if(pNode1->val == pNode2->val) {
            return DoesTree1HaveTree2(pNode1->left, pNode2->left) && DoesTree1HaveTree2(pNode1->right, pNode2->right);
        } else {
            return false;
        }
    }
};