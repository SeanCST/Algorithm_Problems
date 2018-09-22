/* 剑指 Offer - 复杂链表的复制

 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，
 * 一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
 * （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 **/

 /*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        RandomListNode *currNode = pHead;
        // 1. 复制每个结点到当前结点下一个
        while(currNode != NULL) {
            RandomListNode *dNode = new RandomListNode(currNode->label);
            dNode->next = currNode->next;
            currNode->next = dNode;
            currNode = dNode->next;
        }
         
        // 2. 遍历链表，处理复制过的结点的 random 指针
        currNode = pHead;
        while(currNode != NULL) {
            RandomListNode *dNode = currNode->next; // 被复制的结点
            if(currNode->random != NULL) {
                dNode->random = currNode->random->next;
            }
            currNode = dNode->next;
        }
         
        // 3. 拆分，一部分为原链表，一部分为复制链表
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *tmp;
        currNode = pHead;
        while(currNode->next != NULL){
            tmp = currNode->next;
            currNode->next = tmp->next;
            currNode = tmp;
        }
         
        return pCloneHead;
    }
};