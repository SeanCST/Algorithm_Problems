/*
题目描述
给定一个整型矩阵 map，其中的值只有 0 和 1 两种，求其中全是 1 的所有矩形区域中，最大的矩形区域里 1 的数量。

输入描述:
第一行输入两个整数 n 和 m，代表 n*m 的矩阵
接下来输入一个 n*m 的矩阵

输出描述:
输出其中全是 1 的所有矩形区域中，最大的矩形区域里 1 的数量。

示例1
输入
1 4
1 1 1 0

输出
3

说明
最大的矩形区域有3个1，所以返回3

备注:
1 ≤ n, m ≤ 2000
*/

#include <iostream>
#include <stack>
using namespace std;

int maxRecFromBottom(int *height, int length) {
    int maxArea = 0;
    stack<int> stk;
    for(int i = 0; i < length; i++) {
        while(!stk.empty() && height[i] <= height[stk.top()]) {
            int j = stk.top();
            stk.pop();
            int k = stk.empty() ? -1 : stk.top();
            maxArea = max(maxArea, height[j] * (i - k - 1));
        }
        stk.push(i);
    }
    
    while(!stk.empty()) {
        int j = stk.top();
        stk.pop();
        int k = stk.empty() ? -1 : stk.top();
        maxArea = max(maxArea, height[j] * (length - k - 1));
    }
    
    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int **map = new int*[n];
    for(int i = 0; i < n; i++) {
        map[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    
    int maxArea = 0;
    int *height = new int[m];
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            height[j] = map[i][j] == 0 ? 0 : height[j] + 1;
        }
        maxArea = max(maxArea, maxRecFromBottom(height, m));
    }
    
    cout << maxArea;
    
    for(int i = 0; i < n; i++) {
        delete[] map[i];
    } 
    delete[] map;
    delete[] height;
    
    return 0;
}