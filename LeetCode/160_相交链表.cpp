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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0, lengthB = 0;
        ListNode *nodeA = headA, *nodeB = headB;
        while(nodeA != NULL) {
            lengthA++;
            nodeA = nodeA->next;
        }
        while(nodeB != NULL) {
            lengthB++;
            nodeB = nodeB->next;
        }

        if (lengthA > lengthB) {
            int k = lengthA - lengthB;
            while(k-- > 0){
                headA = headA->next;
            }
        }
        
        if (lengthB > lengthA) {
            int k = lengthB - lengthA;
            while(k-- > 0){
                headB = headB->next;
            }
        }

        while(headA != NULL){
            if(headA == headB)
                return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode *pA = headA, *pB = headB;
        while(pA != pB) {
            pA = pA == NULL ? headB : pA->next;
            pB = pB == NULL ? headA : pB->next;
        }
        return pA;
    }
};