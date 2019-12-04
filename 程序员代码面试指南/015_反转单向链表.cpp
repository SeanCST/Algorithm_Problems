/*
题目描述
实现反转单向链表和双向链表的函数。
如 1->2->3 反转后变成 3->2->1。

输入描述:
第一行一个整数 n，表示单链表的长度。
第二行 n 个整数 val 表示单链表的各个节点。
第三行一个整数 m，表示双链表的长度。
第四行 m 个整数 val 表示双链表的各个节点。

输出描述:
在给定的函数内返回相应链表的头指针。

示例1
输入
3
1 2 3
4
1 2 3 4

输出
3 2 1
4 3 2 1

备注:
1 ≤ n , m ≤ 1000000
−1000000 ≤ val ≤ 1000000
*/
# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};
struct double_list_node{
    int val;
    struct double_list_node * pre, * next;
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

double_list_node * input_double_list(void)
{
    int n, val;
    double_list_node * phead = new double_list_node();
    double_list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
            cur_pnode->pre = NULL;
        }
        else {
            double_list_node * new_pnode = new double_list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            new_pnode->pre = cur_pnode;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}

list_node * reverse_list(list_node * head)
{
    //////在下面完成代码
    list_node *reversedHead = NULL;
    list_node *pNode = head;
    while(pNode != NULL) {
        list_node *pNext = pNode->next;
        pNode->next = reversedHead;
        reversedHead = pNode;
        pNode = pNext;
    }
    
    return reversedHead;
}

double_list_node * reverse_double_list(double_list_node * head)
{
    //////在下面完成代码
    double_list_node *reversedHead = NULL;
    double_list_node *pNode = head;
    while(pNode != NULL) {
        double_list_node *pNext = pNode->next;
        pNode->next = reversedHead;
        pNode->pre = pNext;
        reversedHead = pNode;
        pNode = pNext;
    }
    
    return reversedHead;
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

void print_double_list(double_list_node * head)
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
    double_list_node * double_head = input_double_list();
    list_node * new_head = reverse_list(head);
    double_list_node * new_double_head = reverse_double_list(double_head);
    print_list(new_head);
    print_double_list(new_double_head);
    return 0;
}