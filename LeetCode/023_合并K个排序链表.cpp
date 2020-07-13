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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return NULL;
        }
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>& lists, int begin, int end) {
        if(begin == end) {
            return lists[begin];
        }

        int mid = begin + (end - begin) / 2;
        ListNode *left = merge(lists, begin, mid);
        ListNode *right = merge(lists, mid + 1, end);

        return mergeTwoLists(left, right);
    }

    ListNode* mergeTwoLists(ListNode *list1, ListNode *list2) {
        if(list1 == NULL) {
            return list2;
        } else if(list2 == NULL) {
            return list1;
        }  

        ListNode *header = NULL;
        ListNode *pNode = NULL;
        if(list1->val < list2->val){
            header = list1;
            list1 = list1->next;
        } else {
            header = list2;
            list2 = list2->next;
        }
        pNode = header;

        while(list1 != NULL && list2 != NULL) {
            if(list1->val < list2->val){
                pNode->next = list1;
                list1 = list1->next;
            } else {
                pNode->next = list2;
                list2 = list2->next;
            }
            pNode = pNode->next;
        }

        if(list1 != NULL) {
            pNode->next = list1;
        } else if(list2 != NULL) {
            pNode->next = list2;
        }

        return header;
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
    struct cmp {
        bool operator () (ListNode const *n1, ListNode const *n2) {
            return n1->val > n2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return NULL;
        }

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        ListNode *header = NULL;
        ListNode *pNode = NULL;
        while(!pq.empty()) {
            ListNode *node = pq.top();
            pq.pop();
            if(header == NULL) {
                header = node;
                pNode = node; 
            } else {
                pNode->next = node;
                pNode = pNode->next;
            }
  
            if(node != NULL && node->next != NULL ) {
                node = node->next;
                pq.push(node);
            }
        }

        return header;
    }
};