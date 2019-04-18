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
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        vector<int> nums;
        inOrder(root, nums);
        
        int i = 0, j = nums.size() - 1;
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum == k)
                return true;
            else if(sum < k)
                i++;
            else 
                j--;
        }
        
        return false;
    }
    
    void inOrder(TreeNode* t, vector<int>& nums) {
        if(t == NULL) return;
        inOrder(t->left, nums);
        nums.push_back(t->val);
        inOrder(t->right, nums);
    }
};