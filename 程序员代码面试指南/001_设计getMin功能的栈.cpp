/*
题目描述
实现一个特殊功能的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作。

输入描述:
第一行输入一个整数N，表示对栈进行的操作总数。
下面N行每行输入一个字符串S，表示操作的种类。
如果S为"push"，则后面还有一个整数X表示向栈里压入整数X。
如果S为"pop"，则表示弹出栈顶操作。
如果S为"getMin"，则表示询问当前栈中的最小元素是多少。

输出描述:
对于每个getMin操作，输出一行表示当前栈中的最小元素是多少。

示例1
输入
6
push 3
push 2
push 1
getMin
pop
getMin
输出
1
2

备注:
1<=N<=1000000
-1000000<=X<=1000000
数据保证没有不合法的操作
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
    private:
        stack<int> normalStack;
        stack<int> minStack;
    
    public:
        void push(int x) {
            normalStack.push(x);
            if(minStack.empty() || minStack.top() > x) {
                minStack.push(x);
            } else {
                minStack.push(minStack.top());
            }
        }
    
        void pop() {
            if(!normalStack.empty()) {
                normalStack.pop();
                minStack.pop();
            } else {
                throw out_of_range("");
            }
        }
    
        int top() {
            return normalStack.top();
        }
    
        int getMin() {
            return minStack.top();
        }
};

int main() {
    int N;
    cin >> N;
    string str;
    int num;
    Solution s;
    for(int i = 0; i < N; i++) {
        cin >> str;
        if(str == "push") {
            cin >> num;
            s.push(num);
        } else if(str == "pop") {
            s.pop();
        } else if(str == "getMin") {
            cout << s.getMin() << endl;
        }
    }
    
    return 0;
}