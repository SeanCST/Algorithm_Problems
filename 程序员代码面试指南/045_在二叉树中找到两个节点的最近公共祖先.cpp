#include <iostream>
#include <map>
#include <set>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

//     // 采用后序遍历
// tree_node* nearestCommonAncestor(tree_node *root, tree_node *o1, tree_node *o2) {
//     if(root == NULL || root == o1 || root == o2) {
//         return root;
//     }
    
//     tree_node *left = nearestCommonAncestor(root->left, o1, o2);
//     tree_node *right = nearestCommonAncestor(root->right, o1, o2);
    
//     if(left != NULL && right != NULL) {
//         return root;
//     }
    
//     return left != NULL ? left : right;
// }

class Record {
private:
    map<tree_node*, tree_node*> parentMap;

    void setMap(tree_node *root) {
        if (root == NULL) {
            return;
        }
        if(root->left) {
            parentMap[root->left] = root;
            setMap(root->left);
        }
        if(root->right) {
            parentMap[root->right] = root;
            setMap(root->right);
        }
    }

public:
    Record(tree_node *root) {
        if(root) {
            parentMap[root] = NULL;
        }
        setMap(root);
    }

    tree_node* query(tree_node *o1, tree_node *o2) {
        set<tree_node *> o1Path;
        while(parentMap.count(o1) > 0) {
            o1Path.insert(o1);
            o1 = parentMap[o1];
        }

        while(!o1Path.count(o2)) {
            o2 = parentMap[o2];
        }

        return o2;
    }
};


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
    
    int o1, o2;
    cin >> o1 >> o2;
    tree_node *o1Node = nodes[o1];
    tree_node *o2Node = nodes[o2];
    
    // tree_node *res = nearestCommonAncestor(root, o1Node, o2Node);

    Record rec = Record(root);
    tree_node *res = rec.query(o1Node, o2Node);
    cout << res->val;
        
    return 0;
}