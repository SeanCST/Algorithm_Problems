#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

string serialByPre(tree_node *root) {
    if(!root) {
        return "#!";
    }
    string serial = to_string(root->val) + "!";
    serial += serialByPre(root->left);
    serial += serialByPre(root->right);
    
    return serial;
}

string serialByLevel(tree_node *root) {
    if(!root) {
       return "#!";
    } 
    
    string serial = "";
    queue<tree_node *> q;
    q.push(root);
    while(!q.empty()) {
        tree_node *node = q.front();
        q.pop();
        if(node) {
            serial += to_string(node->val) + "!";
            q.push(node->left);
            q.push(node->right);
        } else {
            serial += "#!";
        }
    }
    
    return serial;
}

int main() {
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
    
    cout << serialByPre(root) << endl;
    cout << serialByLevel(root) << endl;
    
    return 0;
}