#include <iostream>
#include <map>
#include <string>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

string getSpace(int num) {
    string spaces = "";
    while(num--) {
        spaces += " ";
    }
    return spaces;
}

void printInOrder(tree_node *root, int height, string to, int len) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->right, height + 1, "v", len);
    string val = to + to_string(root->val) + to;
    int lenM = val.length();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;
    val = getSpace(lenL) + val + getSpace(lenM);
    cout << getSpace(height * len) + val << endl;
    printInOrder(root->left, height + 1, "^", len);
}

void printTree(tree_node *root) {
    printInOrder(root, 0, "H", 17);
    cout << endl;
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

    printTree(root);

    return 0;
}