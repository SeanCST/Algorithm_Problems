#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

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
    
    int m, o1, o2;
    cin >> m;
    vector<vector<int> > queryData(m, vector<int>(2, 0));
    for(int i = 0; i < m; i++) {
        cin >> o1 >> o2;
        queryData[i][0] = o1;
        queryData[i][1] = o2;
    }
    
    Record rec = Record(root);
    for(int i = 0; i < m; i++) {
        tree_node *o1Node = nodes[queryData[i][0]];
        tree_node *o2Node = nodes[queryData[i][1]];
        tree_node *res = rec.query(o1Node, o2Node);
        cout << res->val << endl;
    }
        
    return 0;
}