/*
题目描述
给出一个单链表，返回删除单链表的倒数第 K 个节点的链表。

输入描述:
n 表示链表的长度。
val 表示链表中节点的值。

输出描述:
在给定的函数内返回链表的头指针。

示例1
输入
5 4
1 2 3 4 5

输出
1 3 4 5

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

list_node * remove_last_kth_node(list_node * head, int K)
{
    //////在下面完成代码
    if(head == NULL || K < 1) return head;
    
    list_node *frontNode = head;
    list_node *behindNode = head;
    
    while(K--) {
        if(frontNode) {
            frontNode = frontNode->next;
        } else {
            return head;
        }
    }
    
    while(frontNode->next) {
        frontNode = frontNode->next;
        behindNode = behindNode->next;
    }
    
    list_node *deleteNode = behindNode->next;
    behindNode->next = deleteNode->next;
    delete deleteNode;
    
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
    list_node * rhead = remove_last_kth_node(head, K);
    print_list(rhead);
    return 0;
}