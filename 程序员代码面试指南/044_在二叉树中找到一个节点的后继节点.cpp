#include <iostream>
#include <map>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    tree_node *parent;
    
    tree_node(int v, tree_node *p) : val(v), parent(p),left(NULL), right(NULL){}
};

tree_node* getNextNode(tree_node *node) {
    // 1.  右孩子不为空：结果为右孩子中最左的结点
    // 2.  右孩子为空：
    //     2.1 父亲不为空：
    //         若是父结点的左孩子，则结果为父结点
    //         若是父结点的右孩子，则继续往上找，直到当前节点为父结点的左孩子，则结果为此父结点
    //     2.2 父亲为空，即本结点为根结点，且没有右孩子，那么结果为 NULL
    
    if(node && node->right) {
        tree_node *cur = node->right;
        while(cur->left){
            cur = cur->left;
        }
        return cur;
    }
    
    if(node && node->parent) {
        while(node->parent) {
            tree_node *cur = node->parent;
            if(node == cur->left) {
                return cur;
            } else {
                node = cur;
            }
        }
    }
    
    return NULL;
}

int main () {
    int n, r;
    cin >> n >> r;
    tree_node *root = new tree_node(r, NULL);
    map<int, tree_node*> nodes;
    nodes[r] = root;
    
    int fa, lch, rch;
    for(int i = 0; i < n; i++) {
        cin >> fa >> lch >> rch;
        tree_node *node = nodes[fa];
        if(lch != 0) {
            tree_node *left = new tree_node(lch, node);
            node->left = left;
            nodes[lch] = left;
        }
        if(rch != 0) {
            tree_node *right = new tree_node(rch, node);
            node->right = right;
            nodes[rch] = right;
        }
    }

    int findNodeVal;
    cin >> findNodeVal;
    tree_node *node = nodes[findNodeVal];

    tree_node *next = getNextNode(node);
    int res = next ? next->val : 0;
    cout << res;
    
    return 0;
}