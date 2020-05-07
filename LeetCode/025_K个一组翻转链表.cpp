
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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *preNode = dummy;
        ListNode *nextHead = NULL;

        while(1) {
            ListNode *pNode = preNode;
            int count = 0;
            while(count < k && pNode->next != NULL) {
                pNode = pNode->next;
                count++;
            }
            if(count == k) {
                nextHead = pNode->next;
                pNode->next = NULL;
                ListNode *curHead = preNode->next;
                preNode->next = reverse(curHead);
                preNode = curHead;
                preNode->next = nextHead;
            } else {
                break;
            }
        }

        return dummy->next;
    }

    ListNode *reverse(ListNode* head) {
        ListNode *reversedHead = NULL;
        while(head != NULL) {
            ListNode *pNext = head->next;
            head->next = reversedHead;
            reversedHead = head;
            head = pNext;
        }

        return reversedHead;
    }
};

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
    ListNode* reverse(ListNode *head) {
        ListNode *reversedHead = NULL;
        while(head != NULL) {
            ListNode *pNode = head;
            head = head->next;
            pNode->next = reversedHead;
            reversedHead = pNode;
        }

        return reversedHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy; // pre 一直指向已经翻转好的那一段的尾部结点，也就是待翻转部分的前一个结点
        ListNode *end = dummy;

        while(end->next != NULL) {
            // end 要指向待翻转这一段的最后一个结点
            for(int i = 0; i < k && end != NULL; i++) {
                end = end->next;
            }
            if(end == NULL) { // 如果 end 为空，则代表这一段不满 k 个结点，直接结束
                break;
            }
            ListNode *start = pre->next; // 待翻转这段的第一个结点
            ListNode *next = end->next; // 待翻转这段的后面段的第一个结点
            end->next = NULL;
            pre->next = reverse(start); // 翻转本段并连接到上一段
            start->next = next; // start 经过翻转之后指向翻转这段的尾结点，将其与后面连接起来

            pre = start;
            end = pre;
        }

        return dummy->next;
    }
};