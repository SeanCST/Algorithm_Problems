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
    void deleteNode(ListNode* node) {
        if(node->next != NULL) {
            ListNode *deletedNode = node->next;
            node->val = deletedNode->val;
            node->next = deletedNode->next;
            delete(deletedNode);
        }
    }
};


class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL) {
            return;
        }
        if(node->next == NULL) {
            node = NULL;
            return;
        }

        node->val = node->next->val;
        node->next = node->next->next;
    }
};