#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

string serialByPre(tree_node *root) {
    if(root == NULL) {
        return "#!";
    }
    string res = to_string(root->val) + "!";
    res += serialByPre(root->left);
    res += serialByPre(root->right);

    return res;
}

vector<int> getNextArray(string m) {
    if (m.length() == 1) {
        vector<int> res(1, -1);
        return res;
    }
    vector<int> next(m.length(), 0);
    next[0] = -1;
    next[1] = 0;
    int pos = 2;
    int cn = 0;

    while (pos < next.size()) {
        if (m[pos - 1] == m[cn]) {
            next[pos++] = ++cn;
        } else if(cn > 0) {
            cn = next[cn];
        } else {
             next[pos++] = 0;
        }
    }
    
    return next;
}

// KMP
int getIndexOf(string s, string m) {
    if(m.length() < 1 || s.length() < m.length()) {
        return -1;
    }

    int si = 0, mi = 0;
    vector<int> next = getNextArray(m);
    while (si < s.length() && mi < m.length()) {
        if(s[si] == m[mi]) {
            si++;
            mi++;
        } else if (next[mi] == -1) {
            si++;
        } else {
            mi = next[mi];
        }        
    }
    
    return mi == m.length() ? (si - mi) : -1;
}

// 时间复杂度为 O(M + N) 的解法，序列化之后用 KMP 算法
bool containsTopoSubTree(tree_node *root1, tree_node *root2) {
    string root1Str = serialByPre(root1);
    string root2Str = serialByPre(root2);

    return getIndexOf(root1Str, root2Str) != -1;
}


// bool isEqualTopo(tree_node *root1, tree_node *root2) {
//     if(root1 == NULL && root2 == NULL) {
//         return true;
//     }
//     if(root1 != NULL && root2 != NULL) {
//         if(root1->val != root2->val) {
//             return false;
//         }
//         return isEqualTopo(root1->left, root2->left) && isEqualTopo(root1->right, root2->right);
//     }
    
//     // 一个为 NULL，一个不为 NULL
//     return false; 
// }

// 时间复杂度为 O(M * N) 的解法
// bool containsTopoSubTree(tree_node *root1, tree_node *root2) {
//     if(root2 == NULL) {
//         return true;
//     }
//     if(root1 == NULL) {
//         return false;
//     }
    
//     return isEqualTopo(root1, root2) || 
//            containsTopoSubTree(root1->left, root2) || 
//            containsTopoSubTree(root1->right, root2);
// }

int main () {
    int n, r1;
    cin >> n >> r1;
    tree_node *root1 = new tree_node(r1);
    map<int, tree_node*> nodes1;
    nodes1[r1] = root1;
    
    int fa, lch, rch;
    for(int i = 0; i < n; i++) {
        cin >> fa >> lch >> rch;
        tree_node *node = nodes1[fa];
        if(lch != 0) {
            tree_node *left = new tree_node(lch);
            node->left = left;
            nodes1[lch] = left;
        }
        if(rch != 0) {
            tree_node *right = new tree_node(rch);
            node->right = right;
            nodes1[rch] = right;
        }
    }
    
    int m, r2;
    cin >> m >> r2;
    tree_node *root2 = new tree_node(r2);
    map<int, tree_node*> nodes2;
    nodes2[r2] = root2;
    
    for(int i = 0; i < m; i++) {
        cin >> fa >> lch >> rch;
        tree_node *node = nodes2[fa];
        if(lch != 0) {
            tree_node *left = new tree_node(lch);
            node->left = left;
            nodes2[lch] = left;
        }
        if(rch != 0) {
            tree_node *right = new tree_node(rch);
            node->right = right;
            nodes2[rch] = right;
        }
    }
    
    if(containsTopoSubTree(root1, root2)) {
        cout << "true";
    } else {
        cout << "false";
    }
    
    return 0;
}