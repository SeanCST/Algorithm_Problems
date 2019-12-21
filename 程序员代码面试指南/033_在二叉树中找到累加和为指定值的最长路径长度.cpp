#include <iostream>
#include <map>
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    
    tree_node(int v) : val(v), left(NULL), right(NULL){}
};

int preOrder(tree_node *curNode, int sum, int preSum, int level, int maxLen, map<int, int>& sumMap) {
    if(curNode == NULL) {
        return maxLen;
    }
    
    int curSum = curNode->val + preSum; // 从根结点到当前节点的和
    if(sumMap.count(curSum) == 0) { // sumMap 只保存最靠近根节点的 sum 的 level （到底下 sum 可能会重复）
        sumMap[curSum] = level;
    }
    if(sumMap.count(curSum - sum) > 0) { // 长度为当前结点到上面结点差为 sum 的结点 的 度之差
        maxLen = max(maxLen, level - sumMap[curSum - sum]);
    }
    
    maxLen = preOrder(curNode->left, sum, curSum, level + 1, maxLen, sumMap);
    maxLen = preOrder(curNode->right, sum, curSum, level + 1, maxLen, sumMap);
    
    if(level == sumMap[curSum]) { // 清除掉已经递归完成了的结点的高度
        sumMap.erase(curSum);
    }
    
    return maxLen;
}

int longestPathLength(tree_node *root, int sum) {
    map<int, int> sumMap; // key ：某个累加和  value：这个累加和在路劲中最早出现的层数
    sumMap[0] = 0; // 累加和 0 不用包含任何结点就可以得到
    return preOrder(root, sum, 0, 1, 0, sumMap);
}

int main () {
    int n, r, sum;
    cin >> n >> r;
    tree_node *root = new tree_node(r);
    map<int, tree_node*> nodes;
    nodes[r] = root;
    
    int fa, lch, rch, val;
    for(int i = 0; i < n; i++) {
        cin >> fa >> lch >> rch >> val;
        tree_node *node = nodes[fa];
        node->val = val;
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
    
    cin >> sum;
    cout << longestPathLength(root, sum);
    
    return 0;
}