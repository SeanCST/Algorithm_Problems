#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 不构建二叉树的方法

// int setPost(vector<int> preOrder, int pi, int pj, 
//             vector<int> inOrder, int ii, int ij, 
//             vector<int>& postOrder, int si, map<int, int> inOrderMap) {
//     if (pi > pj) {
//         return si;
//     }
//     postOrder[si--] = preOrder[pi];
//     int i = inOrderMap[preOrder[pi]]; // 获得先序遍历首个数在中序遍历中的下标
//     si = setPost(preOrder, pj - (ij - i) + 1, pj, inOrder, i + 1, ij, postOrder, si, inOrderMap); // 后半部分
//     return setPost(preOrder, pi + 1, pi + i - ii, inOrder, ii, i - 1, postOrder, si, inOrderMap); // 前半部分
// }

// vector<int> getPostOrder(vector<int> preOrder, vector<int> inOrder) {
//     int len = preOrder.size();
//     vector<int> postOrder(len, 0);

//     map<int, int> inOrderMap; // inOrder 中每个数的下标值
//     for(int i = 0; i < len; i++) {
//         inOrderMap[inOrder[i]] = i;
//     }

//     setPost(preOrder, 0, len - 1, inOrder, 0, len - 1, postOrder, len - 1, inOrderMap);

//     return postOrder;
// }


// 构建出二叉树的方法

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

tree_node* generateTree(vector<int> preOrder, int pl, int pr, vector<int> inOrder, int il, int ir) {
    if(pl > pr) {
        return NULL;
    }

    int leftLen = 0;
    for (int i = il; i <= ir; i++) {
        if (inOrder[i] == preOrder[pl]) { // 找到 preOrder 中首位数在 inOrder 中的下标 i
            leftLen = i - il;
            break;
        }
    }
    // int rightLen = pr - pl - leftLen;

    tree_node *root = new tree_node(preOrder[pl]);
    root->left = generateTree(preOrder, pl + 1, pl + leftLen, inOrder, il, il + leftLen - 1);
    root->right = generateTree(preOrder, pl + leftLen + 1, pr, inOrder, il + leftLen + 1, ir);

    return root;
}

void postOrder(tree_node *root, vector<int>& posOrder) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left, posOrder);
    postOrder(root->right, posOrder);
    posOrder.push_back(root->val);
}

vector<int> getPostOrder(vector<int> preOrder, vector<int> inOrder) {
    int len = preOrder.size();
    tree_node *root = generateTree(preOrder, 0, len - 1, inOrder, 0, len - 1);

    vector<int> posOrder;
    postOrder(root, posOrder);

    return posOrder;
}

int main() {
    int n;
    cin >> n;
    vector<int> preOrder(n, 0);
    vector<int> inOrder(n, 0);

    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        preOrder[i] = x;
    }
    for(int i = 0; i < n; i++) {
        cin >> x;
        inOrder[i] = x;
    }
    
    vector<int> postOrder = getPostOrder(preOrder, inOrder);
    for (int i = 0; i < n; i++) {
        cout << postOrder[i] << " ";
    }
    
    return 0;
}