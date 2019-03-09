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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true; // 链表为空或只有一个结点，则是回文链表
        if(head->next->next == NULL) { // 链表只有两个结点，看两个结点值是否相同 
            return head->val == head->next->val;
        }
        
        // 使用快慢两个指针找到中点
        ListNode *slow = head->next, *fast = head->next->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 旋转后半部分结点
        ListNode *reverse = slow, *last = NULL;
        while(reverse != NULL) {
            ListNode *temp = reverse->next;
            reverse->next = last;
            last = reverse;
            reverse = temp;
        }
        
        // 比较前半部分和后半部分是否为回文
        while(last != NULL) {
            if(head->val != last->val)
                return false;
            head = head->next;
            last = last->next;
        }
        
        return true;
    }
};