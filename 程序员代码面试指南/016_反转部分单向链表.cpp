# include <bits/stdc++.h>
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


list_node * reverse_list(list_node * head, int L, int R)
{
    //////在下面完成代码
    // 先遍历一遍，找到第 L 个节点，第 R 个节点，若链表不满足 1 <= L <= R <= N，则不用调整
    list_node *LNode = NULL, *RNode = NULL, pNode = head;
    list_node *LPre = NULL, *RNext = NULL;
    int i = 0;
    while(pNode) {
        i++;
        if(i == L - 1) {
            LPre = pNode;
        }
        if(i == L) {
            LNode = pNode;
        }
        if(i == R){
            RNode = pNode;
            RNext = pNode->next;
        } 
        pNode = pNode->next;
    }
    
    if(LNode && RNode) {
        pNode = LNode;
        list_node *reversedHead = NULL;
        while(pNode != RNext) {
            list_node *pNext = pNode->next;
            pNode->next = reversedHead;
            reversedHead = pNode;
            if(pNext == RNext) {
                break;
            } else {
                pNode = pNext;
            }
        }
        if(LPre) {
            LPre->next = reversedHead;
            LNode->next = RNext;
            return head;
        } else {
            LNode->next = RNext;
            return reversedHead;
        }
    } else {
        return head;
    }
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
    int L, R;
    list_node * head = input_list();
    scanf("%d%d", &L, &R);
    list_node * new_head = reverse_list(head, L, R);
    print_list(new_head);
    return 0;
}