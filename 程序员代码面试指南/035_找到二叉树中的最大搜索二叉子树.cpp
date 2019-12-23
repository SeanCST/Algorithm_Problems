#include <iostream>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

struct return_type {
    tree_node *maxBSTHead;
    int maxBSTSize;
    int min;
    int max;
    
    return_type(tree_node *maxBSTH, int maxSize, int minVal, int maxVal) {
        maxBSTHead = maxBSTH;
        maxBSTSize = maxSize;
        max = maxVal;
        min = minVal;
    }
};

return_type* maxBST(tree_node *node) {
    if(node == NULL) {
        return_type *returnData = new return_type(NULL, 0, INT_MAX, INT_MIN);
        return returnData;
    }
    
    return_type *leftData = maxBST(node->left);
    return_type *rightData = maxBST(node->right);
    int minVal = min(node->val, min(leftData->min, rightData->min));
    int maxVal = max(node->val, max(leftData->max, rightData->max));
    int maxBSTSize = max(leftData->maxBSTSize, rightData->maxBSTSize);
    tree_node* maxBSTHead = leftData->maxBSTSize >= rightData->maxBSTSize ? leftData->maxBSTHead : rightData->maxBSTHead;
    
    if(leftData->maxBSTHead == node->left && rightData->maxBSTHead == node->right &&
       node->val <= rightData->min && node->val >= leftData->max) {
        maxBSTSize = 1 + leftData->maxBSTSize + rightData->maxBSTSize;
        maxBSTHead = node;
    }
    
    return_type *returnData = new return_type(maxBSTHead, maxBSTSize, minVal, maxVal);
    return returnData;
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
    
    return_type *resultData = maxBST(root);
    cout << resultData->maxBSTSize;
    
    return 0;
}
