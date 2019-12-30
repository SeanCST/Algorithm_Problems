#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

bool isBST(tree_node *root) {
    stack<tree_node *> stk;
    int lastVal = INT_MIN;
    while(!stk.empty() || root) {
        if(root) {
            stk.push(root);
            root = root->left;
        } else {
            tree_node *top = stk.top();
            stk.pop();
            if(top->val < lastVal) {
                return false;
            }
            lastVal = top->val;
            root = top->right;
        }
    }
    
    return true;
}

bool isCBT(tree_node *root) {
    if(!root) {
        return true;
    }
    queue<tree_node *> q;
    q.push(root);
    bool allLeaf = false; // 之后全为叶子结点
    while(!q.empty()) {
        tree_node *node = q.front();
        q.pop();
        tree_node *l = node->left;
        tree_node *r = node->right;
        
        // 若有右子树而无左子树，则不是完全二叉树
        if((allLeaf && (l || r)) || (!l && r)) {
            return false;
        }
        
        if(l) {
            q.push(l);
        }
        
        if(r) {
            q.push(r);
        } else { // 有左子树而无右子树，则之后应该全为叶子结点
            allLeaf = true;
        }
    }
    
    return true;
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
    
    if(isBST(root)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    if(isCBT(root)) {
        cout << "true";
    } else {
        cout << "false";
    }
    
    return 0;
}