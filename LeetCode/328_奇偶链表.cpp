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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        
        ListNode *oddHead = head;
        ListNode *evenHead = head->next;
        
        ListNode *oddNode = oddHead;
        ListNode *evenNode = evenHead;
        
        while(oddNode->next != NULL && evenNode->next != NULL) {
            ListNode *nextOddNode = evenNode->next;
            oddNode->next = nextOddNode;
            ListNode *nextEvenNode = nextOddNode->next;
            evenNode->next = nextEvenNode;
            evenNode = nextEvenNode;
            oddNode = nextOddNode;
        }
        
        oddNode->next = evenHead;
        
        return oddHead;
    }
};