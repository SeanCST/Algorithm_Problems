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
    ListNode* swapPairs(ListNode* head) {
        ListNode *h = new ListNode(-1);  // 头结点
        h->next = head;
        
        ListNode *pNode = h;
        while(pNode->next != NULL && pNode->next->next != NULL) {
            ListNode *pFirst = pNode->next;
            ListNode *pSecond = pFirst->next;
            pNode->next = pSecond;
            pFirst->next = pSecond->next;
            pSecond->next = pFirst;
            
            pNode = pFirst;
        }
        
        return h->next;
    }
};