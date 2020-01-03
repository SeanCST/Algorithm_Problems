#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

struct ReturnType {
    bool isBalanced;
    int height;
    ReturnType(bool isBal, int h) : isBalanced(isBal), height(h) {};
};

ReturnType* isBalance(tree_node *root) {
    if(root == NULL) {
        ReturnType *r = new ReturnType(true, 0);
        return r;
    }
    
    ReturnType *leftData = isBalance(root->left);
    ReturnType *rightData = isBalance(root->right);
    
    int height = max(leftData->height, rightData->height) + 1;
    bool isBal = leftData->isBalanced && 
                 rightData->isBalanced && 
                 (abs(leftData->height - rightData->height) <= 1);
    
    ReturnType *r = new ReturnType(isBal, height);
    return r;
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
    
    if(isBalance(root)->isBalanced) {
        cout << "true";
    } else {
        cout << "false";
    }
    
    return 0;
}