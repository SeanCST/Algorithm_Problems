/*
题目描述
给定数组 arr 和整数 num，共返回有多少个子数组满足如下情况：
max(arr[i...j] - min(arr[i...j]) <= num
max(arr[i...j])表示子数组arr[i...j]中的最大值，min[arr[i...j])表示子数组arr[i...j]中的最小值。

输入描述:
第一行输入两个数 n 和 num，其中 n 表示数组 arr 的长度
第二行输入 n 个整数 Xi，表示数组 arr 中的每个元素

输出描述:
输出给定数组中满足条件的子数组个数

示例1
输入
5 2 
1 2 3 4 5

输出
12

备注:
1 ≤ n ≤ 1000000
−1000000 ≤ arr_i​ ≤ 1000000
0 ≤ num ≤ 2000000
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int count(vector<int> arr, int num) {
    if(arr.size() == 0 || num < 0) {
        return 0;
    }
    int i = 0, j = 0, res = 0;
    deque<int> minq, maxq;
    while(i < arr.size()) {
        while (j < arr.size()) {
            if(minq.empty() || minq.back() != j) { // 此处为 maxq 也一样
                while (!minq.empty() && arr[minq.back()] >= arr[j]) {
                    minq.pop_back();
                }
                minq.push_back(j);
                while (!maxq.empty() && arr[maxq.back()] <= arr[j]) {
                    maxq.pop_back();
                }
                maxq.push_back(j);
            }
            
            if(arr[maxq.front()] - arr[minq.front()] > num) {
                break;
            } 
            j++;
        }
        
        res += j - i; // arr[i...i] ... arr[i...j-1] 这些数组都是满足的情况，所以共有 j - i 个
        
        if(i == minq.front()) {
            minq.pop_front();
        }
        if(i == maxq.front()) {
            maxq.pop_front();
        }
        i++;
    }

    return res;
}

int main() {
    int n; 
    int num;
    cin >> n >> num;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    
    cout << count(arr, num);
    
    return 0;
}