/*
题目描述
给定一个链表，再给定一个整数 pivot，请将链表调整为左部分都是值小于 pivot 的节点，中间部分都是值等于 pivot 的节点， 右边部分都是大于 pivot 的节点。
除此之外，对调整后的节点顺序没有更多要求。

输入描述:
第一行两个整数 n 和 pivot，n 表示链表的长度。
第二行 n 个整数 ai 表示链表的节点。

输出描述:
请在给定的函数内返回链表的头指针。

示例1
输入
5 3
9 0 4 5 1

输出
1 0 4 5 9

备注:
1 ≤ n ≤ 1000000
−1000000 ≤ a_i, pivot ≤ 1000000
*/
# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

int pivot;

list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d%d", &n, &pivot);
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


list_node * list_partition(list_node * head, int pivot)
{
    //////在下面完成代码
    if(head == NULL || head->next == NULL) {
        return head;
    }
    list_node *leftHead = NULL, *leftTail = NULL, *midHead = NULL, *midTail = NULL, *rightHead = NULL, *rightTail = NULL;
    list_node *pNode = head;
    
    while(pNode) {
        if(pNode->val < pivot) {
            if(!leftHead) {
                leftHead = pNode;
            } else {
                leftTail->next = pNode;
            }
            leftTail = pNode;
        } else if(pNode->val > pivot) {
            if(!rightHead) {
                rightHead = pNode;
            } else {
                rightTail->next = pNode;
            }
            rightTail = pNode;
        } else {
            if(!midHead) {
                midHead = pNode;
            } else {
                midTail->next = pNode;
            }
            midTail = pNode;
        }
        pNode = pNode->next;
    }
    
    list_node *newHead = NULL;
    if(rightHead) {
        rightTail->next = newHead;
        newHead = rightHead;
    }
    if(midHead) {
        midTail->next = newHead;
        newHead = midHead;
    }
    if(leftHead) {
        leftTail->next = newHead;
        newHead = leftHead;
    }
    
    pNode = newHead;
    while (pNode) {
        cout << pNode->val << " ";
        pNode = pNode->next;
    }
    
    return newHead;
}


int main ()
{
    list_node * head = input_list();
    list_partition(head, pivot);
    return 0;
}