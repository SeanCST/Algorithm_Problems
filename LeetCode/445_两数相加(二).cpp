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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1, s2;
        while(l1 != NULL) {
            s1.push(l1);
            l1 = l1->next;
        }
        while(l2 != NULL) {
            s2.push(l2);
            l2 = l2->next;
        }
        
        ListNode *h = new ListNode(-1);
        int carry = 0;
        while(!s1.empty() || !s2.empty() || carry) {
            int x = 0;
            if(!s1.empty()) {
                x = s1.top()->val;
                s1.pop();
            }
            int y = 0;
            if(!s2.empty()) {
                y = s2.top()->val;
                s2.pop();
            }
            int sum = x + y + carry;
            if(sum >= 10) {
                carry = 1;
                sum %= 10;
            } else {
                carry = 0;
            }
            ListNode *node = new ListNode(sum);
            node->next = h->next;
            h->next = node;
        }
        
        return h->next;
    }

};