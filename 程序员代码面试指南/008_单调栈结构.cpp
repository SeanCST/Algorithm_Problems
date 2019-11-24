/*
题目描述
给定一个可能含有重复值的数组 arr，找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置。返回所有位置相应的信息。

输入描述:
第一行输入一个数字 n，表示数组 arr 的长度。
以下一行输入 n 个数字，表示数组的值

输出描述:
输出n行，每行两个数字 L 和 R，如果不存在，则值为 -1，下标从 0 开始。

示例1
输入
7
3 4 1 5 6 2 7

输出
-1 2
0 2
-1 -1
2 5
3 5
2 -1
5 -1

备注:
1≤n≤1000000
−1000000 ≤ arr_i ≤ 1000000
*/

// #include <iostream>
// #include <stack>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     int *arr = new int[n];
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
    
//     //动态开辟空间
//     int **res = new int*[n]; //开辟行
// 	for(int i = 0; i < n; i++) {
//         res[i] = new int[2]; //开辟列
//     }

//     // 使用单调栈结构解题
//     stack<int> monotonicStack;
//     for(int i = 0; i < n; i++) {
//         while(!monotonicStack.empty() && arr[monotonicStack.top()] > arr[i]) {
//             int popIndex = monotonicStack.top();
//             monotonicStack.pop();
//             res[popIndex][1] = i;
//             res[popIndex][0] = monotonicStack.empty() ? -1 : monotonicStack.top();
//         }
//         monotonicStack.push(i);
//     }

//     while(!monotonicStack.empty()) {
//         int popIndex = monotonicStack.top();
//         monotonicStack.pop();
//         res[popIndex][0] = monotonicStack.empty() ? -1 : monotonicStack.top();
//         res[popIndex][1] = -1;
//     }

//     for (int i = 0; i < n; i++) {
//         cout << res[i][0] << " " << res[i][1] << endl;
//     }

//     //释放开辟的资源
//     for(int i = 0; i < n; i++)
// 		delete[] res[i];
// 	delete[] res;
// }


/// 进阶版，arr 中数字可能相同
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int **res = new int*[n];
    for(int i = 0; i < n; i++) {
        res[i] = new int[2];
    }
    
    stack<vector<int> > stk;
    for(int i = 0; i < n; i++) {
        while(!stk.empty() && arr[stk.top()[0]] > arr[i]) {
            vector<int> popVec = stk.top();
            stk.pop();
            int leftLessIndex = stk.empty() ? -1 : stk.top()[stk.top().size() - 1];
            for(int j = 0; j < popVec.size(); j++) {
                res[popVec[j]][0] = leftLessIndex;
                res[popVec[j]][1] = i;
            }
        }

        if(!stk.empty() && arr[stk.top()[0]] == arr[i]) {
            stk.top().push_back(i);
            
        } else {
            vector<int> vec;
            vec.push_back(i);
            stk.push(vec);
        }
    }
    
    while (!stk.empty()) {
        vector<int> popVec = stk.top();
        stk.pop();
        int leftLessIndex = stk.empty() ? -1 : stk.top()[stk.top().size() - 1];
        for(int j = 0; j < popVec.size(); j++) {
            res[popVec[j]][0] = leftLessIndex;
            res[popVec[j]][1] = -1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

    //释放开辟的资源
    for(int i = 0; i < n; i++)
        delete[] res[i];
    delete[] res;
    delete[] arr;
    
    return 0;
}