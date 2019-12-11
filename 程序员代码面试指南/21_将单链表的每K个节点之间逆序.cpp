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


list_node * reverse_knode(list_node * head1, int K)
{
    //////在下面完成代码
    if(K <= 1) {
        return head1;
    }
    list_node *pNode = head1;
    int length = 0;
    while(pNode != NULL) {
        length++;
        pNode = pNode->next;
    }
    list_node *resHead = NULL;
    list_node *curHead = NULL;
    list_node *lastTail = NULL;
    pNode = head1;
    while(length >= K) {
        int curK = K;
        list_node *originHead = pNode;
        curHead = NULL;
        while(curK-- > 0) {
            list_node *pNext = pNode->next;
            pNode->next = curHead;
            curHead = pNode;
            pNode = pNext;
        }
        if(resHead == NULL) {
            resHead = curHead;
        }
        if(lastTail && curHead) {
            lastTail->next = curHead;
        }
        lastTail = originHead;
        length -= K;
    }
    if(lastTail && pNode) {
        lastTail->next = pNode;
    }
    
    return resHead;
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
    int K;
    scanf("%d", &K);
    list_node * new_head = reverse_knode(head, K);
    print_list(new_head);
    return 0;
}