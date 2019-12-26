#include <iostream>
#include <map>
#include <queue>
#include <deque>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

void printByLevel(tree_node *root) {
    if(!root) {
        return;
    }
    queue<tree_node* > q;
    q.push(root);
    int curLevel = 1;
    tree_node *curLevelLastNode = root;
    tree_node *curNode = root;

    cout << "Level " << curLevel++ << " : ";

    while(!q.empty()) {
        tree_node *node = q.front();
        q.pop();
        cout << node->val << " ";
        
        if (node->left) {
            q.push(node->left);
            curNode = node->left;
        }
        if (node->right) {
            q.push(node->right);
            curNode = node->right;
        }
        
        if(curLevelLastNode == node && !q.empty()) {
            curLevelLastNode = curNode;
            cout << endl << "Level " << curLevel++ << " : ";
        }
    }

    cout << endl;
}

void printLevelAndOrientation(int level, bool isOdd) {
    cout << "Level " << level << " ";
    if (isOdd) {
        cout << "from left to right: ";
    } else {
        cout << "from right to left: ";
    }
}

void printByZigZag(tree_node *root) {
    if(!root) {
        return;
    }
    deque<tree_node *> dq;
    dq.push_back(root);
    int curLevel = 1;
    tree_node *curLevelLastNode = root;
    tree_node *curNode = root;
    bool isOdd = true;
    printLevelAndOrientation(curLevel++, isOdd);

    while(!dq.empty()) {
        tree_node *node = NULL;
        if (isOdd) {
            node = dq.front();
            dq.pop_front();
            if (node->left) {
                dq.push_back(node->left);
                curNode = node->left;
            }
            if (node->right) {
                dq.push_back(node->right);
                curNode = node->right;
            }
        } else {
            node = dq.back();
            dq.pop_back();
            if (node->right) {
                dq.push_front(node->right);
                curNode = node->right;
            }
            if (node->left) {
                dq.push_front(node->left);
                curNode = node->left;
            }
        }
        
        cout << node->val << " ";

        if(curLevelLastNode == node && !dq.empty()) {
            cout << endl;
            curLevelLastNode = dq.empty() ? NULL : (isOdd ? dq.front() : dq.back());
            isOdd = !isOdd;
            printLevelAndOrientation(curLevel++, isOdd);
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
    
    printByLevel(root);
    printByZigZag(root);
    
    return 0;
}