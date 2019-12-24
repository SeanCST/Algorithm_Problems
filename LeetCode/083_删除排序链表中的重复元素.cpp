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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) 
            return head;
            
        ListNode *p = head;
        ListNode *q = p->next;
        while(q != NULL){
            if(p->val == q->val) {
                p->next = q->next;
                delete q;
            } else {
                 p = p->next;
            }
            q = p->next;
        }
        
        return head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;

        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }
};