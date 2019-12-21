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


list_node * merge_list(list_node * head1, list_node * head2)
{
    //////在下面完成代码
    if(!head1 || !head2) {
        return head1 ? head1 : head2;
    }
    list_node *newHead = head1->val >= head2->val ? head2 : head1;
    head1 = newHead == head1 ? head1->next : head1;
    head2 = newHead == head2 ? head2->next : head2;
    list_node *pNode = newHead;
    while(head1 && head2) {
        if(head1->val >= head2->val) {
            pNode->next = head2;
            pNode = pNode->next;
            head2 = head2->next;
        } else {
            pNode->next = head1;
            pNode = pNode->next;
            head1 = head1->next;
        }
    }
    pNode->next = head1 ? head1 : head2;
    
    return newHead;
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
    list_node * head1 = input_list();
    list_node * head2 = input_list();
    list_node * new_head = merge_list(head1, head2);
    print_list(new_head);
    return 0;
}