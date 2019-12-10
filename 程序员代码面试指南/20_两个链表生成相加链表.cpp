# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(int n)
{
    int val;
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


list_node * add_list(list_node * head1, list_node * head2)
{
    //////在下面完成代码
    stack<list_node *> stk1, stk2;
    list_node *pNode1 = head1, *pNode2 = head2;
    while(pNode1) {
        stk1.push(pNode1);
        pNode1 = pNode1->next;
    }
    while(pNode2) {
        stk2.push(pNode2);
        pNode2 = pNode2->next;
    }
    
    list_node *resHead = NULL;
    int carry = 0;
    while(!stk1.empty() || !stk2.empty()) {
        int val1 = 0, val2 = 0;
        if(!stk1.empty()) {
            pNode1 = stk1.top();
            stk1.pop();
            val1 = pNode1->val;
        }
        if(!stk2.empty()) {
            pNode2 = stk2.top();
            stk2.pop();
            val2 = pNode2->val;
        }
        int sum = val1 + val2 + carry;
        carry = sum >= 10 ? 1 : 0;
        list_node *node = new list_node();
        node->val = sum % 10;
        node->next = resHead;
        resHead = node;
    }
    if(carry == 1) {
        list_node *node = new list_node();
        node->val = 1;
        node->next = resHead;
        resHead = node;
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
    int n, m;
    scanf("%d%d", &n, &m);
    list_node * head1 = input_list(n), * head2 = input_list(m);
    list_node * new_head = add_list(head1, head2);
    print_list(new_head);
    return 0;
}