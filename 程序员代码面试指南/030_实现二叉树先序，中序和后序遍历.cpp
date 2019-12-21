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

void preOrderRecur(tree_node *root) {
    if(!root) {
        return;
    }
    
    cout << root->val << " ";
    preOrderRecur(root->left);
    preOrderRecur(root->right);
}

void inOrderRecur(tree_node *root) {
    if(!root) {
        return;
    }
    
    inOrderRecur(root->left);
    cout << root->val << " ";
    inOrderRecur(root->right);
}

void postOrderRecur(tree_node *root) {
    if(!root) {
        return;
    }
    
    postOrderRecur(root->left);
    postOrderRecur(root->right);
    cout << root->val << " ";
}

void preOrderUnRecur(tree_node *root) {
    if (!root) {
        return;
    }        
    stack<tree_node *> stk;
    stk.push(root);
    while (!stk.empty()) {
        tree_node *node = stk.top();
        stk.pop();
        cout << node->val << " ";
        // 前序遍历：先将右子树入栈、再将左子树入栈
        if (node->right) {
            stk.push(node->right);
        }
        if (node->left) {
            stk.push(node->left);
        }
    }
}

void inOrderUnRecur(tree_node *root) {
    if (!root) {
        return;
    }    
    stack<tree_node *> stk;
    while (!stk.empty() || root) {
        if (root) { // 若当前节点不为空，则一直往栈中 push 当前节点，并对其左孩子做循环操作
            stk.push(root);
            root = root->left;
        } else { // 若当前节点为空，说明刚设的左孩子或右孩子为 NULL，那么取栈顶节点，接着对栈顶节点进行操作，在设右孩子之前打印出结点值
            root = stk.top();
            stk.pop();
            cout << root->val << " ";
            root = root->right;
        }
    }
}

void postOrderUnRecur1(tree_node *root) {
    if (!root) {
        return;
    }    
    // 参考先序方式反过来
    stack<tree_node *> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        tree_node *node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) {
            s1.push(node->left);
        }
        if (node->right) {
            s1.push(node->right);
        }
    }
    
    while (!s2.empty()) {
        cout << s2.top()->val << " ";
        s2.pop();
    }
}

void postOrderUnRecur2(tree_node *root) {
    if (!root) {
        return;
    }    
    
    stack<tree_node *> stk;
    stk.push(root);
    tree_node *h = root; // h 的意义是最近一次弹出并打印的节点
    tree_node *c = NULL; // c 的意义是 stack 的栈顶节点
    while (!stk.empty()) {
        c = stk.top();
        if(c->left && h != c->left && h != c->right) { // 左子树存在且左子树还没处理
            stk.push(c->left);
        } else if (c->right && h != c->right) { // 右子树存在且右子树还没处理
            stk.push(c->right);
        } else { // c 的左子树和右子树都已经打印完毕，那么从 stk 中弹出 c 并打印，然后令 h 为 c
            stk.pop();
            cout << c->val << " ";
            h = c;
        }
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
    
    // preOrderRecur(root);
    preOrderUnRecur(root);
    cout << endl;
    // inOrderRecur(root);
    inOrderUnRecur(root);
    cout << endl;
    // postOrderRecur(root);
    // postOrderUnRecur1(root);    
    postOrderUnRecur2(root);    
}