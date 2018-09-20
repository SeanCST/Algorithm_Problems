/*  剑指 Offer - 链表中倒数第k个结点

 * 输入一个链表，输出该链表中倒数第k个结点。
 **/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k==0)
            return NULL;
        
        ListNode *front = pListHead, *back = pListHead;
        for(int i = 1; i < k; i++) {
            if(front->next != NULL)
                front = front->next;
            else
                return NULL;
        }
        
        while(front->next != NULL) {
            front = front->next;
            back = back->next;
        }
        
        return back;
    }
};