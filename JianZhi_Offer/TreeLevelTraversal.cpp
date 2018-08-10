/* 剑指 offer - 从上往下打印二叉树

 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        
        vector <int> res;  // 要返回的结果
        queue <TreeNode*> q;  // 操作队列
        
        if(root != NULL)
            q.push(root);  // 先将根结点加入队列
        
        while(!q.empty()) {
            TreeNode *frontNode = q.front();
            res.push_back(frontNode->val);  // 将队首结点的值加入到返回的结果之中
            
            // 若队首结点有左结点，将其左结点插入队列；右同
            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
            
            q.pop();  // pop 队首结点
        }
        
        return res;
    }
};