#include <iostream>
#include <map>
#include <stack>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

void findTwoErrorNodes(tree_node *root) {
    if(!root) {
        return;
    }
    tree_node *errNode1 = NULL;
    tree_node *errNode2 = NULL;
    tree_node *lastNode = NULL;
    // 中序遍历
    stack<tree_node *> stk;
    while(!stk.empty() || root) {
        if(root) {
            stk.push(root);
            root = root->left;
        } else {
            root = stk.top();
            stk.pop();
            if(lastNode && root->val < lastNode->val) {
                if(errNode1 == NULL) {
                    errNode1 = lastNode;
                } else {
                    errNode2 = root; 
                }
            }
            lastNode = root;
            root = root->right;
        }
    }
    
    if(errNode2) {
        cout << errNode2->val << " ";
    }
    if(errNode1) {
        cout << errNode1->val;
    }
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
    
    findTwoErrorNodes(root);
    
    return 0;
}