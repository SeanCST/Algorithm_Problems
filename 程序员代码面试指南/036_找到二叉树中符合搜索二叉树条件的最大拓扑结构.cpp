#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

// bool isBSTNode(tree_node *h, tree_node *n, int value) {
//     if(h == NULL) {
//         return false;
//     }
//     if(h == n) {
//         return true;
//     }
//     return isBSTNode(h->val > value ? h->left : h->right, n, value);
// }

// int maxTopo(tree_node *h, tree_node *n) {
//     if(h != NULL && n != NULL && isBSTNode(h, n, n->val)) {
//         return maxTopo(h, n->left) + maxTopo(h, n->right) + 1;
//     }
    
//     return 0;
// }

// int bestTopoSize1(tree_node *head) {
//     if(head == NULL) {
//         return 0;
//     }
    
//     int maxSize = maxTopo(head, head);
//     maxSize = max(bestTopoSize1(head->left), maxSize);
//     maxSize = max(bestTopoSize1(head->right), maxSize);
    
//     return maxSize;
// }

struct Record
{
    int l;
    int r;

    Record(int left, int right) : l(left), r(right) {}
};

int modifyMap(tree_node *n, int v, map<tree_node *, Record *>& m, bool s) {
    if (n == NULL || m.count(n) == 0) {
        return 0;
    }

    Record *r = m[n];
    if ((s && n->val > v) || ((!s) && n->val < v)) {
        m.erase(n);
        return r->l + r->r + 1;
    } else {
        int minus = modifyMap(s ? n->right : n->left, v, m, s);
        if (s) {
            r->r = r->r - minus;
        } else {
            r->l = r->l - minus;
        }
        m[n] = r;
        return minus;
    }
}

int posOrder(tree_node *h, map<tree_node *, Record *>& m) {
    if (h == NULL) {
        return 0;
    }

    int ls = posOrder(h->left, m);
    int rs = posOrder(h->right, m);
    modifyMap(h->left, h->val, m, true);
    modifyMap(h->right, h->val, m, false);

    Record *lr = NULL;
    Record *rr = NULL;
    if (m.count(h->left) > 0) {
        lr = m[h->left];
    }
    if (m.count(h->right) > 0) {
        rr = m[h->right];
    }

    int lbst = lr == NULL ? 0 : lr->l + lr->r + 1;
    int rbst = rr == NULL ? 0 : rr->l + rr->r + 1;
    Record *record = new Record(lbst, rbst);
    m[h] = record;

    return max(lbst + rbst + 1, max(ls, rs));
}

int bestTopoSize2(tree_node *head) {
    map<tree_node *, Record *> m;
    return posOrder(head, m);
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
    
   cout << bestTopoSize2(root);
    
    return 0;
}