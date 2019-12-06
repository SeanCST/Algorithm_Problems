# include <bits/stdc++.h>
#include <stack>
using namespace std;
 
struct list_node{
    int val;
    struct list_node * next;
};
 
list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}
 
// // O(n) 空间复杂度
// list_node * check(list_node * head)
// {
//     //////在下面完成代码

//     if(head == NULL || head->next == NULL) {
//         cout << "true";
//         return head;
//     }
    
//     stack<list_node *> stk;
    
//     list_node *pSlow = head, *pFast = head;
//     while(pFast != NULL && pFast->next != NULL) {
//         stk.push(pSlow);
//         pSlow = pSlow->next;
//         pFast = pFast->next->next;
//     }

//     bool res = true;
     
//     list_node *pNode = pFast ? pSlow->next : pSlow;
//     while(pNode) {
//         list_node *top = stk.top();
//         stk.pop();
//         if(pNode->val != top->val) {
//             res = false;
//             break;
//         }
//         pNode = pNode->next;
//     }
//     if(res) {
//         cout << "true";
//     } else {
//         cout << "false";
//     }
     
//     return head;
// }


// O(1) 空间复杂度
list_node * check(list_node * head)
{
    //////在下面完成代码
    if(head == NULL || head->next == NULL) {
        cout << "true";
        return head;
    }    
    list_node *pSlow = head, *pFast = head;
    while(pFast != NULL && pFast->next != NULL) {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
    }

    bool res = true;
    
    // pNode 为后半区的第一个节点
    list_node *pNode = pFast ? pSlow->next : pSlow;

    // 翻转后半区
    list_node *reversedHead = NULL;
    // 翻转完成后后半区头为 reversedHead
    while(pNode) {
        list_node *pNext = pNode->next;
        pNode->next = reversedHead;
        reversedHead = pNode;
        pNode = pNext;
    }
    
    pNode = head;
    list_node *rNode = reversedHead;
    // 回文检查
    while(rNode) {
        if(pNode->val != rNode->val) {
            res = false;
            break;
        }
        pNode = pNode->next;
        rNode = rNode->next;
    }
    
    // 将翻转过的链表还原，前半区链表的最后一个节点为 pSlow
    pNode = reversedHead;
    reversedHead = NULL;
    while(pNode) {
        list_node *pNext = pNode->next;
        pNode->next = reversedHead;
        reversedHead = pNode;
        pNode = pNext;
    }
    pSlow->next = reversedHead;
  
    if(res) {
        cout << "true";
    } else {
        cout << "false";
    }
     
    return head;
}
 
 
int main ()
{
    int L, R;
    list_node * head = input_list();
    check(head);
    return 0;
}