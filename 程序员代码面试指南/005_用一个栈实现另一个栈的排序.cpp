/*
题目描述：
一个栈中元素的类型为整型，现在想将该栈从顶到底按从大到小的顺序排序，只许申请一个栈。除此之外，可以申请新的变量，但不能申请额外的数据结构。如何完成排序？

输入描述：
第一行输入一个 N，表示栈中元素的个数
第二行输入 N 个整数 a_i 表示栈顶到栈底的各个元素

输出描述:
输出一行表示排序后的栈中栈顶到栈底的各个元素。

示例1
输入
5
5 8 4 3 6

输出
8 6 5 4 3

备注:
1 <= N <= 10000
-1000000 <= a_n​ <= 1000000
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
    private:
        stack<int> temp;
    public:
        void sortStack(stack<int> &s) {
            while(!s.empty()) {
                int cur = s.top();
                s.pop();
                if(temp.empty() || temp.top() > cur) {
                    temp.push(cur);
                } else {
                    while(!temp.empty() && temp.top() < cur) {
                        s.push(temp.top());
                        temp.pop();
                    }
                    temp.push(cur);
                }
            }
            
            while(!temp.empty()) {
                s.push(temp.top());
                temp.pop();
            }
        }
};

int main() {
    int N;
    int x;
    cin >> N;
    stack<int> s;
    for(int i = 0; i < N; i++) {
        cin >> x;
        s.push(x);
    }
    Solution sol;
    sol.sortStack(s);
    // 输出
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
