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


list_node * selection_sort(list_node * head)
{
    //////在下面完成代码
    // 选择排序，每次在当前未排序的结点部分选择一个值最小的结点，接到已排序部分的后面
    list_node *sortedHead = NULL;
    list_node *sortedTail = NULL;
    list_node *pNode = head;
    while(pNode) {
        list_node *cur = pNode, *min = pNode, *minPre = NULL;
        // 找到未排序节点中最小的
        while(cur->next) {
            if(cur->next->val < min->val) {
                minPre = cur;
                min = cur->next;
            }
            cur = cur->next;
        }
        // 将找到的最小的结点接到已排序部分之后
        if(minPre) { // min 不是第一个结点
            minPre->next = min->next;
        } else { // min 是第一个结点
            pNode = pNode->next;
        }
        if(sortedHead) {
            sortedTail->next = min;
        } else {
            sortedHead = min;
        }
        sortedTail = min;
    }
    
    return sortedHead;
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
    list_node * new_head = selection_sort(head);
    print_list(new_head);
    return 0;
}