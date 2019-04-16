/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);
        
        ListNode *pre = preMid(head);
        ListNode *mid = pre->next;
        pre->next = NULL;
        TreeNode *t = new TreeNode(mid->val);
        t->left = sortedListToBST(head);
        t->right = sortedListToBST(mid->next);
        
        return t;
    }
    
    ListNode* preMid(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        ListNode *pre = head;
        
        while(fast != NULL && fast->next != NULL) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return pre;
    }
};