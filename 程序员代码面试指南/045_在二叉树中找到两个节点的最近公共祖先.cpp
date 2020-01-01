#include <iostream>
#include <map>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

// 采用后序遍历
tree_node* nearestCommonAncestor(tree_node *root, tree_node *o1, tree_node *o2) {
    if(root == NULL || root == o1 || root == o2) {
        return root;
    }
    
    tree_node *left = nearestCommonAncestor(root->left, o1, o2);
    tree_node *right = nearestCommonAncestor(root->right, o1, o2);
    
    if(left != NULL && right != NULL) {
        return root;
    }
    
    return left != NULL ? left : right;
}

int main () {
    int n, r;
    cin >> n >> r;
    tree_node *root = new tree_node(r);
    map<int, tree_node*> nodes;
    nodes[r] = root;
    
    int fa, lch, rch;
    for(int i = 0; i < n; i++) {
        cin >> fa >> lch >> rch;
        tree_node *node = nodes[fa];
        if(lch != 0) {
            tree_node *left = new tree_node(lch);
            node->left = left;
            nodes[lch] = left;
        }
        if(rch != 0) {
            tree_node *right = new tree_node(rch);
            node->right = right;
            nodes[rch] = right;
        }
    }
    
    int o1, o2;
    cin >> o1 >> o2;
    tree_node *o1Node = nodes[o1];
    tree_node *o2Node = nodes[o2];
    
    tree_node *res = nearestCommonAncestor(root, o1Node, o2Node);
    cout << res->val;
        
    return 0;
}