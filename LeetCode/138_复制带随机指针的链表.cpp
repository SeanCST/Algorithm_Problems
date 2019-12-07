/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) {
            return NULL;
        }
        Node *pNode = head;

        // 复制一遍节点并插入到原节点后面
        while(pNode) {
            Node *pCopy = new Node(pNode->val, NULL, NULL);
            Node *pNext = pNode->next;
            pNode->next = pCopy;
            pCopy->next = pNext;
            pNode = pNext;
        }

        // 赋值 random
        pNode = head;
        while(pNode) {
            Node *pCopy = pNode->next;
            pCopy->random = pNode->random ? pNode->random->next : NULL;
            pNode = pCopy->next;
        }

        // 解开原链表与复制的链表
        Node *pCopyHead = head->next;
        pNode = head;
        while(pNode) {
            Node *pCopy = pNode->next;
            Node *pNext = pCopy->next;
            pNode->next = pNext;
            pCopy->next = pNext ? pNext->next : NULL;

            pNode = pNext;
        }

        return pCopyHead;
    }
};