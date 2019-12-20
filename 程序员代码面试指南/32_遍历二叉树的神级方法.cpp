#include <iostream>
#include <map>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

void morris(tree_node *root) {
    if(root == NULL) {
        return;
    }
    
    tree_node *cur = root;
    tree_node *mostRight = NULL;
    
    while(cur != NULL) {
        cout << cur->val << " ";
        mostRight = cur->left;
        if(mostRight != NULL) { // 如果当前 cur 有左子树
            // 找到 cur 左子树上最右的节点
            while(mostRight->right != NULL && mostRight->right != cur) {
                mostRight = mostRight->right;
            }
            if(mostRight->right == NULL) { // 若 mostRight 的 right 指针指向空，则改为指向 cur，且 cur 向左移动
                mostRight->right = cur;
                cur = cur->left;
                continue;
            } else { // mostRight 的 right 指针指向 cur，则还原为指向 cur
                mostRight->right = NULL;
            }
        } 
        // 若 cur 没有左子树或者左子树上最右节点的右指针指向 cur（表示已经遍历到最右了），cur 向右移动
        cur = cur->right;
    }
}

// 对于所有能到达两次的节点（有左子树的节点），第一次到达打印，第二次到达不打印
void morrisPre(tree_node *root) {
    if(root == NULL) {
        return;
    }
    
    tree_node *cur = root;
    tree_node *mostRight = NULL;
    
    while(cur != NULL) {
        mostRight = cur->left;
        if(mostRight != NULL) { // 如果当前 cur 有左子树
            // 找到 cur 左子树上最右的节点
            while(mostRight->right != NULL && mostRight->right != cur) {
                mostRight = mostRight->right;
            }
            if(mostRight->right == NULL) { // 若 mostRight 的 right 指针指向空，则改为指向 cur，且 cur 向左移动
                mostRight->right = cur;
                cout << cur->val << " "; // 刚找到 mostRight，说明是第一次到达 cur，打印 cur 的值
                cur = cur->left;
                continue;
            } else { // mostRight 的 right 指针指向 cur，则还原为指向 cur
                mostRight->right = NULL;
            }
        } else { // 当前 cur 没有左子树，直接打印
            cout << cur->val << " ";
        }
        // 若 cur 没有左子树或者左子树上最右节点的右指针指向 cur（表示已经遍历到最右了），cur 向右移动
        cur = cur->right;
    }

    cout << endl;
}

// 对于所有能到达两次的节点（有左子树的节点），第一次到达不打印，第二次到达打印
void morrisIn(tree_node *root) {
    if(root == NULL) {
        return;
    }
    
    tree_node *cur = root;
    tree_node *mostRight = NULL;
    
    while(cur != NULL) {
        mostRight = cur->left;
        if(mostRight != NULL) { // 如果当前 cur 有左子树
            // 找到 cur 左子树上最右的节点
            while(mostRight->right != NULL && mostRight->right != cur) {
                mostRight = mostRight->right;
            }
            if(mostRight->right == NULL) { // 若 mostRight 的 right 指针指向空，则改为指向 cur，且 cur 向左移动
                mostRight->right = cur;
                cur = cur->left;
                continue;
            } else { // mostRight 的 right 指针指向 cur，则还原为指向 cur
                mostRight->right = NULL;
            }
        }
        // 若 cur 没有左子树或者左子树上最右节点的右指针指向 cur（表示已经遍历到最右了），cur 向右移动
        cout << cur->val << " "; 
        cur = cur->right;
    }

    cout << endl;
}

tree_node* reverseEdge(tree_node *from) {
    tree_node *pre = NULL;
    tree_node *next = NULL;
    while (from) {
        next = from->right;
        from->right = pre;
        pre = from;
        from = next;
    }
    return pre;
}

void printEdge(tree_node *root) {
    tree_node *tail = reverseEdge(root); // 逆序
    tree_node *cur = tail;
    while (cur) {
        cout << cur->val  << " ";
        cur = cur->right;
    }
    reverseEdge(tail); // 再逆序回来
}

void morrisPos(tree_node *root) {
    if(root == NULL) {
        return;
    }
    tree_node *cur = root;
    tree_node *mostRight = NULL;
    
    while(cur != NULL) {
        mostRight = cur->left;
        if(mostRight != NULL) { // 如果当前 cur 有左子树
            // 找到 cur 左子树上最右的节点
            while(mostRight->right != NULL && mostRight->right != cur) {
                mostRight = mostRight->right;
            }
            if(mostRight->right == NULL) { // 若 mostRight 的 right 指针指向空，则改为指向 cur，且 cur 向左移动
                mostRight->right = cur;
                cur = cur->left;
                continue;
            } else { // mostRight 的 right 指针指向 cur，则还原为指向 cur
                mostRight->right = NULL;
                printEdge(cur->left); // 第二次到达时，逆序打印左子树的右边界
            }
        } 
        // 若 cur 没有左子树或者左子树上最右节点的右指针指向 cur（表示已经遍历到最右了），cur 向右移动
        cur = cur->right;
    }

    printEdge(root); // 最后，逆序打印整棵树的右边界
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
     
    // morris(root);
    morrisPre(root);
    morrisIn(root);
    morrisPos(root);
    
    return 0;
}