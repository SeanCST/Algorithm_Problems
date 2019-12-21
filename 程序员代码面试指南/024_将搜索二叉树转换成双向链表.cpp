# include <bits/stdc++.h>
using namespace std;

struct double_list_node{
    int val;
    struct double_list_node * pre, * next;
};

struct BST{
    int val;
    struct BST * lch, * rch;
};

struct ReturnType {
    double_list_node *start;
    double_list_node *end;
    ReturnType(double_list_node *s, double_list_node *e) {
        start = s;
        end = e;
    }
};

BST * input_BST()
{
    int n, fa, lch, rch;
    scanf("%d", &n);
    BST * root, * new_node;
    map<int, BST *> mp;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &fa, &lch, &rch);
        if (mp.find(fa) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[fa] = new_node;
            new_node->val = fa;
            if (i == 1) root = new_node;
        }
        if (lch && mp.find(lch) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[lch] = new_node;
            new_node->val = lch; new_node->lch = new_node->rch = NULL;
        }
        if (rch && mp.find(rch) == mp.end()) {
            new_node = (BST *)malloc(sizeof(BST));
            mp[rch] = new_node;
            new_node->val = rch; new_node->lch = new_node->rch = NULL;
        }
        mp[fa]->lch = (lch ? mp[lch] : NULL);
        mp[fa]->rch = (rch ? mp[rch] : NULL);
    }
    return root;
}

ReturnType * process(BST *root) {
    if(!root) {
        return new ReturnType(NULL, NULL);
    }
    
    double_list_node *head = new double_list_node();
    head->val = root->val;
    ReturnType *left = process(root->lch);
    ReturnType *right = process(root->rch);
    if(left->end) {
        left->end->next = head;
    }
    head->pre = left->end;
    head->next = right->start;
    if(right->start) {
        right->start->pre = head;
    }
    
    ReturnType *res = new ReturnType(left->start ? left->start : head, right->end ? right->end : head);
    return res;
}

double_list_node * convert(BST * root)
{
    //////在下面完成代码
    if (!root) {
        return NULL;
    }
    
    return process(root)->start;
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
    BST * root = input_BST();
    double_list_node * new_double_head = convert(root);
    print_double_list(new_double_head);
    return 0;
}