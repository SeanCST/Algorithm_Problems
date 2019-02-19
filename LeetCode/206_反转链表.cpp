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
    // 迭代
    ListNode* reverseList(ListNode* head) {
        ListNode *pNode = NULL;
        
        if(head != NULL) {
            pNode = head->next;
            head->next = NULL;
        }
        
        while(pNode != NULL){
            ListNode *temp = pNode->next;
            pNode->next = head;
            head = pNode;
            pNode = temp;
        }
        
        return head;
    }
};


class Solution {
public:
    // 递归
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *pNode = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return pNode;
    }
};