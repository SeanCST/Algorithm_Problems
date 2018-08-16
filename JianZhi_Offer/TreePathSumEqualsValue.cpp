/* 剑指 Offer - 二叉树中和为某一值的路径

 * 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 * (注意: 在返回值的list中，数组长度大的数组靠前)
 */

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
    vector<vector<int> > res;
    vector<int> currentPath;
public:
    void SearchPath(TreeNode *pNode, int leftVal) {   // left 减掉当前路径已过的结点值的剩余的值
        currentPath.push_back(pNode->val);
        if(leftVal - pNode->val == 0 && pNode->left == NULL && pNode->right == NULL) { // 叶子结点
            res.push_back(currentPath);
        }
        else {
            if(pNode->left)
                SearchPath(pNode->left, leftVal - pNode->val);
            if(pNode->right)
                SearchPath(pNode->right, leftVal - pNode->val);
        }
        // pop
        currentPath.pop_back();
    }

    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        if(root != NULL) 
            SearchPath(root, expectNumber);

        return res;
    }
    
};