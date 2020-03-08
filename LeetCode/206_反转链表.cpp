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
    // ??
    ListNode* reverseList(ListNode* head) {
        ListNode *reversedHead = NULL;
        while(head) {
            ListNode *pNext = head->next;
            head->next = reversedHead;
            reversedHead = head;
            head = pNext;
        }

        return reversedHead;
    }

    // ??
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *pNext = head->next;
        ListNode *reversedHead = reverseList(pNext);
        pNext->next = head;
        head->next = NULL;

        return reversedHead;
    }
};