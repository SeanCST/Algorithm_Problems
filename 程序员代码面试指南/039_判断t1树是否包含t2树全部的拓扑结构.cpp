#include <iostream>
#include <map>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

bool check(tree_node *root1, tree_node *root2) {
    if(root2 == NULL) {
        return true;
    }
    if(root1 == NULL || root1->val != root2->val) {
        return false;
    }
    
    return check(root1->left, root2->left) && check(root1->right, root2->right);
}

bool containsTopo(tree_node *root1, tree_node *root2) {
    if(root2 == NULL) {
        return true;
    }
    if(root1 == NULL) {
        return false;
    }
    
    return check(root1, root2) || 
           containsTopo(root1->left, root2) || 
           containsTopo(root1->right, root2);
}

int main () {
    int n, r1;
    cin >> n >> r1;
    tree_node *root1 = new tree_node(r1);
    map<int, tree_node*> nodes1;
    nodes1[r1] = root1;
    
    int fa, lch, rch;
    for(int i = 0; i < n; i++) {
        cin >> fa >> lch >> rch;
        tree_node *node = nodes1[fa];
        if(lch != 0) {
            tree_node *left = new tree_node(lch);
            node->left = left;
            nodes1[lch] = left;
        }
        if(rch != 0) {
            tree_node *right = new tree_node(rch);
            node->right = right;
            nodes1[rch] = right;
        }
    }
    
    int m, r2;
    cin >> m >> r2;
    tree_node *root2 = new tree_node(r2);
    map<int, tree_node*> nodes2;
    nodes2[r2] = root2;
    
    for(int i = 0; i < m; i++) {
        cin >> fa >> lch >> rch;
        tree_node *node = nodes2[fa];
        if(lch != 0) {
            tree_node *left = new tree_node(lch);
            node->left = left;
            nodes2[lch] = left;
        }
        if(rch != 0) {
            tree_node *right = new tree_node(rch);
            node->right = right;
            nodes2[rch] = right;
        }
    }
    
    if(containsTopo(root1, root2)) {
        cout << "true";
    } else {
        cout << "false";
    }
    
    return 0;
}