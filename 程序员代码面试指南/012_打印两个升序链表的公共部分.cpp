/*题目描述
给定两个升序链表，打印两个升序链表的公共部分。

输入描述:
第一个链表的长度为 n。
第二个链表的长度为 m。
链表结点的值为 val。

输出描述:
输出一行整数表示两个升序链表的公共部分的值 (按升序输出)。

示例1
输入
4
1 2 3 4
5
1 2 3 5 6

输出
1 2 3

备注:
1 ≤ n, m ≤ 1000000
INTMIN ≤ val ≤ INTMAX
*/

# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
}; //链表的节点

list_node * input_list(void) //读入链表
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

void sol(list_node * a_head, list_node * b_head)
{
    //////在下面完成代码
    list_node *pA = a_head;
    list_node *pB = b_head;
    while (pA && pB) {
        if (pA->val == pB->val) {
            cout << pA->val << " ";
            pA = pA->next;
            pB = pB->next;
        } else if (pA->val < pB->val) {
            pA = pA->next;
        } else {
            pB = pB->next;
        }
    }
}

int main ()
{
    list_node * a_head = input_list(); // A 链表的头节点
    list_node * b_head = input_list(); // B 链表的头节点
    sol(a_head, b_head);
    return 0;
}