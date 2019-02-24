/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 0;
        ListNode *frontNode = head, *behindNode = head;
        while(k++ <= n) {
            if(frontNode == NULL) return head->next;
            frontNode = frontNode->next;
        }
        
        // 找到待删除结点
        while(frontNode != NULL) {
            frontNode = frontNode->next;
            behindNode = behindNode->next;
        }
        
        ListNode *deletedNode = behindNode->next;
        behindNode->next = deletedNode->next;
        delete(deletedNode);
        
        return head;
    }
};