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
    ListNode* removeElements(ListNode* head, int val) {
        // 手动添加一个头结点，方便统一操作
        ListNode *header = new ListNode(-1);
        header->next = head;
        ListNode *pNode = header;
        while(pNode->next != NULL) {
            if(pNode->next->val == val) {
                ListNode *delNode = pNode->next;
                pNode->next = delNode->next;
                delete delNode;
            } else {
                pNode = pNode->next;
            }
        }
        
        return header->next;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};