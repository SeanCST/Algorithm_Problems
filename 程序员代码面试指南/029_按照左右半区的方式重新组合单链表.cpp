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


list_node * relocate(list_node * head)
{
    //////在下面完成代码
    list_node *fast = head, *slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // 从 slow 开始为右半区
    list_node *left = head, *right = slow;
    while(left != slow) {
        list_node *leftNext = left->next;
        list_node *rightNext = right->next;
        left->next = right;
        left = leftNext;
        if(left != slow) { // 将当前处理的 right 部分结点连接到下一个要处理的 left 结点
            right->next = leftNext;
        }
        right = rightNext;
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
    list_node * new_head = relocate(head);
    print_list(new_head);
    return 0;
}