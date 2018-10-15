/* 剑指 Offer - 删除链表中重复的结点

 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
 * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 **/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL) return pHead;
        
        /*---------先为链表创建一个头结点---------*/
        int firstNumber = pHead->val;
        //假设我的头结点数值为-1
        int myFirst = -1;
        //万一链表的头结点也为-1，那么我就改成-2
        if (myFirst == firstNumber)
        {
            myFirst = -2;
        }
        ListNode *head = new ListNode(myFirst);
        head->next = pHead;
        
        ListNode *pre = head;
        ListNode *pNode = pre->next;
                
        while(pNode != NULL) {
            while(pNode->next != NULL && pNode->val == pNode->next->val) { // 遇到重复结点，pNode 前进
                pNode = pNode->next;
            } 
            
            if(pre->next != pNode) {  // 进行删除操作
                pre->next = pNode->next;
                pNode = pNode->next;
            } else { // 未遇到重复结点，pre 和 pNode 都前进
                pre = pNode;
                pNode = pNode->next;
            }
        }
        
        return head->next;
    }
};