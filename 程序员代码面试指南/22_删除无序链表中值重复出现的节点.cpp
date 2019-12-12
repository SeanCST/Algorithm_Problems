# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list()
{
    int val, n;
    scanf("%d", &n);
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
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

// 方法1 ： 时间复杂度 O(N)
list_node * remove_rep(list_node * head)
{
    //////在下面完成代码
    if(!head || !head->next) return head;

    map<int, bool> m;
    list_node *pNode = head;
    m[pNode->val] = true;
    while(pNode->next) {
        list_node *pNext = pNode->next;
        if(m[pNext->val]) {
            pNode->next = pNext->next;
            delete pNext;
        } else {
            m[pNext->val] = true;
            pNode = pNext;
        }
    }
    
    return head;
}

// 方法2 ： 空间复杂度 O(1)
list_node * remove_rep(list_node * head)
{
    ////在下面完成代码
    if(!head || !head->next) return head;

    list_node *pCur = head, *pPre = NULL, *pNext = NULL;
    while(pCur) {
        pPre = pCur;
        pNext = pCur->next;
        while(pNext) {
            if (pNext->val == pCur->val) {
                pPre->next = pNext->next;
                delete pNext;
            } else {
                pPre = pNext;
            }
            pNext = pNext->next;
        }
        pCur = pCur->next;
    }
    return head;
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

int main ()
{
    list_node * head = input_list();
    list_node * new_head = remove_rep(head);
    print_list(new_head);
    return 0;
}