/*
题目描述
给定一个链表，实现删除链表第 K 个节点的函数。

输入描述:
n 表示链表的长度。
m 表示删除链表第几个节点。
val 表示链表节点的值。

输出描述:
在给定的函数中返回链表的头指针。

示例1
输入
5 3
1 2 3 4 5

输出
1 2 4 5

备注:
1 ≤ K ≤ n ≤ 1000000
−1000000 ≤ val ≤ 1000000
*/

# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
}; //链表的节点

int K;

list_node * input_list(void) //读入链表
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d %d", &n, &K);
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

list_node * remove_kth_node(list_node * head, int K)
{
    //////在下面完成代码
    if(head == NULL || K <= 0) return head;
    if(K == 1) return head->next;
    
    list_node *pNode = head;
    while(--K != 1) {
        pNode = pNode->next;
        if(pNode == NULL) return head;
    }
    list_node *pDelete = pNode->next;
    if(pDelete == NULL) return head;
    pNode->next = pDelete->next;
    delete pDelete;
    
    return head;
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main ()
{
    list_node * head = input_list(); // 链表的头节点
    list_node * rhead = remove_kth_node(head, K);
    print_list(rhead);
    return 0;
}