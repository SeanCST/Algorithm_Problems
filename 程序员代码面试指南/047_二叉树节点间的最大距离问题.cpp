#include <iostream>
#include <map>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

struct ReturnType {
    int maxDistance;
    int height;
    ReturnType(int mD, int h) : maxDistance(mD), height(h) {}
};

ReturnType* process(tree_node *root) {
    ReturnType *r = new ReturnType(0, 0); 
    if(root == NULL) {
        return r;
    }
    
    ReturnType *leftData = process(root->left);
    ReturnType *rightData = process(root->right);
    
    r->height = max(leftData->height, rightData->height) + 1;
    r->maxDistance = max(leftData->height + rightData->height + 1, max(leftData->maxDistance, rightData->maxDistance));
    
    return r;
}

int getMaxDistance(tree_node *root) {
    ReturnType *data = process(root);
    return data->maxDistance;
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
    
    cout << getMaxDistance(root);
    
    return 0;
}