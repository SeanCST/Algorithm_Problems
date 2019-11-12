/*
题目描述
一个栈依次压入1,2,3,4,5，那么从栈顶到栈底分别为5,4,3,2,1。将这个栈转置后，从栈顶到栈底为1,2,3,4,5，也就是实现栈中元素的逆序，但是只能用递归函数来实现，不能用其他数据结构。

输入描述:
输入数据第一行一个整数N为栈中元素的个数。
接下来一行N个整数X_i表示从栈顶依次到栈底的每个元素。

输出描述:
输出一行表示栈中元素逆序后的每个元素

示例1
输入
5
1 2 3 4 5

输出
5 4 3 2 1

备注:
1<=N<=1000000
-1000000<=X_i<=1000000
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
    public:
        int getAndRemoveLastElement(stack<int> &s) {
            int result = s.top();
            s.pop();
            if(s.empty()) {
                return result;
            } else {
                int last = getAndRemoveLastElement(s);
                s.push(result);
                return last;
            }
        }

        void reverseStack(stack<int> &s) {
            if(s.empty()) {
                return;
            }
            int i = getAndRemoveLastElement(s);
            ReverseStack(s);
            s.push(i);
        }
};

int main() {
    int N, x;
    cin >> N;
    stack<int> s;
    while(N--) {
        cin >> x;
        s.push(x);
    }
    
    Solution sol;
    sol.reverseStack(s);
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}